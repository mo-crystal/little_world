#include"actor.h"

Actor::~Actor()
{
}

std::vector<Point> Actor::GetCollisonArea()
{
  std::vector<Point> res;
  double a = DEFAULT_COLLISON_RANGE * scale, b = DEFAULT_COLLISON_RANGE * scale;
  for (int x = 0; x <= a; ++x)
  {
    double yUpper = sqrt((1 - (x * x) / (a * a)) * (b * b));
    double yLower = -yUpper;
    for (int y = std::ceil(yLower); y <= std::floor(yUpper); ++y)
    {
      res.push_back(Point(x, y));
      res.push_back(Point(x, -y));
      res.push_back(Point(-x, -y));
      res.push_back(Point(-x, y));
    }
  }
  return res;
}