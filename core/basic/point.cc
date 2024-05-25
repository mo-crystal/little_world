#include<point.h>

Point::~Point()
{
}

int Point::get_distance(Point &p){
  return sqrt((this->x-p.get_x())*(this->x-p.get_x())+(this->y-p.get_y())*(this->y-p.get_y()));
}