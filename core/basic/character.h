#ifndef CHARACTER_H
#define CHARACTER_H

#include "renderable_actor.h"

class Character : public RenderableActor
{
private:
public:
  Character(Point p, double scale = 1) : RenderableActor(p, scale) {}
  virtual ~Character();
  virtual void Move() = 0;
};

#endif