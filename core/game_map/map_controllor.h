#ifndef MAP_CONTROLLOR_H
#define MAP_CONTROLLOR_H

#include<sstream>

#include<building.h>

struct map_node
{
  Building * building=NULL;
  Point location;
  map_node* sub[4];
  map_node(Building* b, Point loc) : building(b), location(loc) {
      for (int i = 0; i < 4; ++i) {
        sub[i] = nullptr;
      }
    }
};


class MapControllor
{
private:
  map_node *game_map=NULL;
public:
  int getQuadrant( Point& origin,  Point& p);
  void insertBuilding(map_node*& node, Building* building,  Point& point);
  void removeBuilding(map_node*& node,Point& point);
  void search(map_node* node,Point& top_left,Point& bottom_right, std::vector<map_node*>& result);
  void collectNodes(map_node* node, std::vector<map_node*>& nodes);
  std::vector<Point> get_all_point_in_area(map_node* node);
  MapControllor();
  ~MapControllor();
};




#endif