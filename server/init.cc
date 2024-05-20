#include <user.h>
#include <vector>
#include <mocutils/log.h>

extern std::vector<user> user_manager;

void init_user() {
  moc::log("init user.");
  user_manager.push_back({0, "Test1"});
  user_manager.push_back({1, "Test2"});
}
