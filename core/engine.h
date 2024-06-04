#ifndef ENGINE_H
#define ENGINE_H

#include "./impl_actors/player.h"
#include "./controllers/actor_controller.h"
#include "./controllers/render_controller.h"

#define SERVER 1
#define CLIENT 2

#define ACTORCONTROLLER_TICKTIME 1000

class Engine
{
private:
  std::unordered_map<std::string,Controller *> controllers;
  RenderController *rendercontroller;
  ActorController *actorcontroller;
  std::string mode = "release";
  double TickTime = 0.0167;
  int side;

public:
  Engine(int _side = CLIENT, std::string _mode = "release");
  ~Engine();
  void Init();
  void Start();
  void SetTickTime(double time) { TickTime = time; }
  void AddController(std::string name, Controller *c);
  Controller* GetController(std::string name);
};

#endif