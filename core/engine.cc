#include<engine.h>

Engine::Engine()
{
  mapcontrollor=new MapControllor;
  resourcecontrollor=new ResourceControllor("");
}

Engine::~Engine()
{
  delete mapcontrollor;
}
