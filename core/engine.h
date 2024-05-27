#ifndef ENGINE_H
#define ENGINE_H


#include "./impl_actors/player.h"
#include "./controllers/actor_controller.h"

#define SERVER 1
#define CLIENT 2

class Engine
{
private:
  ActorController *actorcontroller;
  std::string mode = "release";
  double TickTime = 0.0167;
  
public:
  Engine(int side = CLIENT, std::string _mode = "release");
  ~Engine();
  void Init();
  void Start();
  void SetTickTime(double time) { TickTime = time; }
};

#endif