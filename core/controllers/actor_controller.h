#ifndef ACTOR_CONTROLLER_H
#define ACTOR_CONTROLLER_H

#include<vector>
#include<set>

#include "controller.h"
#include "../basic/character.h"
#include "../basic/renderable_actor.h"


class ActorController:public Controller
{
private:
  std::unordered_map<std::string ,Actor *> actors;

public:
  ActorController(Engine * e):Controller(e){}
  ~ActorController();
  void RegisterActor(std::string name,Actor *);
  void TickAtion();
  std::vector<render_data> GetRenderData();
  void Start(double interval);
  void UpdateActorByName(std::string name,std::string state);
};

#endif