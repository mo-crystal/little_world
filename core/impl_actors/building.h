#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <iostream>

#include "../basic/renderable_actor.h"

#define OVAL_A 1
#define OVAL_B 1
#define NO_BUILDING -1
#define NO_OWNER -1

class Building : public RenderableActor
{
private:
  int id = NO_BUILDING;
  int owner_id = NO_OWNER;

public:
  Building(Point p,int _id, int _onwer)
      : id(_id), owner_id(_onwer),RenderableActor(p) {}
  ~Building();
  int getId() { return id; }
  int getOwnerId() { return owner_id; }
};

#endif