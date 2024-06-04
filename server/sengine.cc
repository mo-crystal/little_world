#include "./sengine.h"

Engine *e;

void start_engine() {
  e = new Engine(SERVER);
  e->Init();
  e->Start();
}
