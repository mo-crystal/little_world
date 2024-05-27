#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point
{
private:
  int x, y;

public:
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  Point(const Point &p) : x(p.get_x()), y(p.get_y()) {}
  Point(Point &&p) noexcept : x(p.get_x()), y(p.get_y()) {}
  ~Point();
  int get_x() const { return x; }
  int get_y() const { return y; }
  int get_distance(const Point &p) const;

  Point operator+(const Point &p) const;
  Point operator-(const Point &p) const;
  Point &operator=(const Point &other);
};

#endif // POINT_H