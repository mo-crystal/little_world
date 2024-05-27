#ifndef ACTOR_H
#define ACTOR_H

#include <vector>

#include "point.h"

#define DEFAULT_COLLISON_RANGE 100
#define NO_COLLISION 0

class Actor
{
private:
  Point p;
  double scale = 1;

public:
  Actor(Point _p, double _scale = 1):p(_p),scale(_scale) {}
  virtual ~Actor();
  Point GetLocation() { return p; }
  void SetLocation(Point &_p) { p = _p; }
  double GetScale() { return scale; }
  void SetScale(double _scale) { scale = _scale; }
  std::vector<Point> GetCollisonArea();

  virtual void TickAction() = 0;
};

#endif