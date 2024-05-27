#include "point.h"

Point::~Point()
{
}

int Point::get_distance(const Point &p) const
{
  return sqrt((this->x - p.get_x()) * (this->x - p.get_x()) + (this->y - p.get_y()) * (this->y - p.get_y()));
}

Point Point::operator+(const Point &p) const
{
  return Point(x + p.x, y + p.y);
}
Point Point::operator-(const Point &p) const
{
  return Point(x - p.x, y - p.y);
}
Point &Point::operator=(const Point &other)
{
  if (this != &other)
  {
    x = other.x;
    y = other.y;
  }
  return *this;
}