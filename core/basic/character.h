#ifndef CHARACTER_H
#define CHARACTER_H

#include "renderable_actor.h"

enum direction
{
  NORTH,
  SOUTH,
  WEST,
  EAST
};

class Character : public RenderableActor
{
private:
  direction towards = NORTH;

public:
  Character(Point p, double scale = 1) : RenderableActor(p, scale) {}
  void SetTowards(direction _towards) { towards = _towards; }
  direction GetTowards() { return towards; }
  virtual ~Character();
  virtual void Move() = 0;
};

#endif