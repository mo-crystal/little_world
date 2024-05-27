#ifndef ENGINE_H
#define ENGINE_H

#include "./impl_actors/player.h"


#define SERVER 1
#define CLIENT 2

class Engine
{
private:
  std::string mode = "release";
  double TickTime = 0.0167;
  std::vector<Player*> tmpPlayers;
public:
  Engine(int side = CLIENT, std::string _mode = "release");
  ~Engine();
  void Init();
  void Start();
  void SetTickTime(double time) { TickTime = time; }
};

#endif