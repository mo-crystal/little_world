#include <user.h>
#include <vector>
#include <mocutils/log.h>

extern std::vector<user> users;

void init_user() {
  moc::log("init user.");
  users.push_back({0, "Test1"});
  users.push_back({1, "Test2"});
}
