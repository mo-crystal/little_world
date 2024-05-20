#include <mocutils/log.h>
#include <vector>
#include <user.h>

extern std::vector<user> users;

int main() {
  extern void init_user();
  init_user();
  printf("%d\n", users.size());
  return 0;
}
