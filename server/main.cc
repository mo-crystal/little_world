#include <mocutils/log.h>
#include <vector>
#include <user.h>

extern std::vector<user> user_manager;

int main() {
  extern void init_user();
  init_user();
  printf("%d\n", user_manager.size());
  return 0;
}
