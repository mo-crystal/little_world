#include "suser.h"

std::vector<user> users;

void init_user() {
  users.push_back({0, "Test0", "password0"});
  users.push_back({1, "Test1", "password1"});
  char buf[128];
  sprintf(buf, "User inited. Total: %d", users.size());
  moc::log(std::string(buf));
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
  return prt::bytes("ok");
}
