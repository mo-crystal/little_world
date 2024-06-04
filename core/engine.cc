#include "engine.h"

Engine::Engine(int _side, std::string _mode)
{
  side = _side;
  mode = _mode;
  actorcontroller = new ActorController(this);
  rendercontroller = new RenderController(this);
  inputcontroller = new InputController(this);
  controllers["actorcontroller"] = actorcontroller;
  controllers["rendercontroller"] = rendercontroller;
}

Engine::~Engine()
{
  for (auto i = controllers.begin(); i != controllers.end(); i++)
  {
    delete (*i).second;
  }
}

void Engine::Init()
{
  Point a(480, 320);
  Player *p = new Player(a);
  p->InitStates("D:\\CODE\\C++\\civilization\\src\\client\\res\\game\\c1");
  actorcontroller->RegisterActor("player", p);
}

void Engine::Start()
{
  rendercontroller->Start(TickTime);
  actorcontroller->Start(ACTORCONTROLLER_TICKTIME);
  for (auto i = controllers.begin(); i != controllers.end(); i++)
  {
    (*i).second->Start(TickTime);
  }
}

void Engine::AddController(std::string name, Controller *c)
{
  if (controllers.find(name) == controllers.end())
  {
    controllers[name] = c;
  }
}

Controller *Engine::GetController(std::string name)
{
  if (controllers.find(name) != controllers.end())
  {
    return controllers[name];
  }
  return nullptr;
}