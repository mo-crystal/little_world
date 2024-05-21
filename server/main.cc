#include <mocutils/log.h>
#include <vector>
#include <user.h>

extern std::vector<user> users;
extern void init_user();
extern void init_pyrite();

int main() {
  init_user();
  init_pyrite();
  return 0;
}
