#include "suser.h"
#include "spyrite.h"
#include "sengine.h"

int main() {
  init_user();
  init_pyrite();

  start_engine();
  return 0;
}
