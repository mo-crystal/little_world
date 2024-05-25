#ifndef ENGINE_H
#define ENGINE_H

#include<./game_map/map_controllor.h>
#include<./resource_controllor/resource_controllor.h>

class Engine
{
private:
  MapControllor *mapcontrollor;
  ResourceControllor *resourcecontrollor;
public:
  Engine();
  ~Engine();
};



#endif