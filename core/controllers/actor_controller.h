#ifndef ACTOR_CONTROLLER_H
#define ACTOR_CONTROLLER_H

#include<vector>
#include<set>

#include "../basic/character.h"
#include "../basic/renderable_actor.h"


class ActorController
{
private:
  std::set<Actor *> actors;

public:
  ActorController();
  ~ActorController();
  void RegisterActor(Actor *);
  void TickAtion();
  std::vector<render_data> GetRenderData();
};

#endif