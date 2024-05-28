#include "suser.h"
#include <memory>

std::vector<user> users;

void init_user() {
  users.push_back({0, "Test0", "password0"});
  users.push_back({1, "Test1", "password1"});
  moc::logf("User inited. Total: %d", users.size());
}

int operator<(const sockaddr_in &a, const sockaddr_in &b) {
  int l = sizeof(sockaddr_in);
  return memcmp(&a, &b, l);
}

std::map<sockaddr_in, int> addr_uid;

int get_uid(sockaddr_in addr) {
  if (addr_uid.count(addr) == 0)
    return -1;
  return addr_uid[addr];
}

prt::bytes login(sockaddr_in client_addr, prt::bytes data) {
  user req;
  data.to_mem(&req, sizeof(user));
  int uid = -1;
  for (const auto &u: users) {
    if (u.id != req.id || u.password != req.password)
      continue;
    uid = u.id;
    break;
  }
  if (uid == -1)
    return prt::bytes("wrong id or password");

  addr_uid[client_addr] = uid;
  return prt::bytes("ok");
}

prt::bytes whoami(sockaddr_in client_addr, prt::bytes data) {
  user u{id: get_uid(client_addr)};
  if (u.id != -1)
    u = users[u.id];
  return prt::bytes(&u, sizeof(user));
}
