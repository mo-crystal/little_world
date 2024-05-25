#include<map_controllor.h>

MapControllor::MapControllor()
{
}

MapControllor::~MapControllor()
{
}

int MapControllor::getQuadrant( Point& origin,  Point& p)  {
  if (p.get_x() >= origin.get_x() && p.get_y() > origin.get_y()) return 0; 
  if (p.get_x() < origin.get_x() && p.get_y() > origin.get_y()) return 1;  
  if (p.get_x() < origin.get_x() && p.get_y() <= origin.get_y()) return 2; 
  if (p.get_x() >= origin.get_x() && p.get_y() <= origin.get_y()) return 3;
  return -1;
}

void MapControllor::insertBuilding(map_node*& node, Building* building,  Point& point) {
  if (node == nullptr) {
    node = new map_node(building, point);
    return;
  }
  int quadrant = getQuadrant(node->location, point);
  insertBuilding(node->sub[quadrant], building, point);
}

void MapControllor::removeBuilding(map_node*& node,Point& point) {
  if (node == nullptr) return;
  if (node->location.get_x() == point.get_x() && node->location.get_y() == point.get_y()) {
    delete node;
    node = nullptr;
    return;
  }
  int quadrant = getQuadrant(node->location, point);
  removeBuilding(node->sub[quadrant], point);
}

void MapControllor::search(map_node* node,Point& top_left,Point& bottom_right, std::vector<map_node*>& result) {
  if (node == nullptr) return;
  int x = node->location.get_x();
  int y = node->location.get_y();
  if (x >= top_left.get_x() && x <= bottom_right.get_x() && y >= bottom_right.get_y() && y <= top_left.get_y()) {
    result.push_back(node);
  }

  if (bottom_right.get_x() >= node->location.get_x() && top_left.get_y() > node->location.get_y()) {
    search(node->sub[0], top_left, bottom_right, result);
  }
  if (top_left.get_x() <= node->location.get_x() && top_left.get_y() > node->location.get_y()) {
    search(node->sub[1], top_left, bottom_right, result); 
  }
  if (top_left.get_x() <= node->location.get_x() && bottom_right.get_y() <= node->location.get_y()) {
    search(node->sub[2], top_left, bottom_right, result); 
  }
  if (bottom_right.get_x() >= node->location.get_x() && bottom_right.get_y() <= node->location.get_y()) {
    search(node->sub[3], top_left, bottom_right, result); 
  }
}

void MapControllor::collectNodes(map_node* node, std::vector<map_node*>& nodes) {
  if (node == nullptr) return;
  nodes.push_back(node);
  for (int i = 0; i < 4; ++i) {
    collectNodes(node->sub[i], nodes);
  }
}

std::vector<Point> MapControllor::get_all_point_in_area(map_node* node){
  std::vector<Point> res;
  if(node==nullptr) return res;
  double scale=node->building->getScale();
  double a=OVAL_A*scale,b=OVAL_B*scale;
  std::vector<Point> res;
  for (int x = 0; x <= a; ++x) {
    double yUpper = sqrt((1 - (x * x) / (a * a)) * (b * b));
    double yLower = -yUpper;
    for (int y = std::ceil(yLower); y <= std::floor(yUpper); ++y) {
      res.push_back(Point(x,y));
      res.push_back(Point(x,-y));
      res.push_back(Point(-x,-y));
      res.push_back(Point(-x,y));
    }
  }
  return res;
}
