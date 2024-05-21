#include <user.h>
#include <vector>
#include <pyrite/server.h>
#include <mocutils/log.h>
#include <map>



std::vector<user> users;
std::map<sockaddr_in, int> addr_to_uid;

void init_user() {
  users.push_back({0, "Test1"});
  users.push_back({1, "Test2"});
  char buf[128];
  sprintf(buf, "User inited. Total: %d", users.size());
  moc::log(std::string(buf));
}

prt::bytes login(sockaddr_in client_addr, prt::bytes data) {
  user req;
  data.to_mem(&req, sizeof(user));
  bool uid = -1;
  for (const auto &u: users) {
    if (u.id != req.id || u.password != req.password)
      continue;
    uid = u.id;
    break;
  }
  if (uid == -1)
    return prt::bytes("wrong id or password");

  addr_to_uid[client_addr] = uid;
  return prt::bytes("ok");
}
