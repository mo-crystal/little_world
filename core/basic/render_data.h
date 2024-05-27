#ifndef RENDERABLE_DATA_H
#define RENDERABLE_DATA_H

#include <string>

#include "point.h"


struct render_data
{
  Point p;
  std::string resourceId;

  render_data(Point _p, std::string _resourceId) : p(_p), resourceId(_resourceId) {}
};

#endif