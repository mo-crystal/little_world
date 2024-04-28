#include <log.h>

int main() {
  log("server started.");
  warn("server warn");
  panic("server exit");
  return 0;
}
