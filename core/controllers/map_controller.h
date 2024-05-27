#ifndef MAP_CONTROLLER_H
#define MAP_CONTROLLER_H

#include <sstream>

#include "../impl_actors/building.h"
#include "../basic/point.h"

struct map_node
{
  std::vector<Actor *> actors;
  Point location;
  map_node *sub[4];
  map_node(Actor *actor)
  {
    location = actor->GetLocation();
    actors.push_back(actor);
    for (int i = 0; i < 4; ++i)
    {
      sub[i] = nullptr;
    }
  }
};

class MapController
{
private:
  map_node *game_map = NULL;

public:
  int getQuadrant(Point &origin, Point &p);
  void insertActor(Actor *&actor);
  void removeBuilding(map_node *&node, Point &point);
  void search(map_node *node, Point &top_left, Point &bottom_right, std::vector<map_node *> &result);
  void collectNodes(map_node *node, std::vector<map_node *> &nodes);
  std::vector<Point> get_area(map_node *node);
  MapController();
  ~MapController();
};

#endif