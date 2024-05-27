#include "engine.h"

Engine::Engine(int side, std::string _mode)
{
  mode = _mode;
}

Engine::~Engine()
{
}

void Engine::Init()
{
  Point a(480, 320);
  Player *p = new Player(a);
  p->InitStates("D:\\CODE\\C++\\civilization\\src\\client\\res\\game\\c1");
  tmpPlayers.push_back(p);
}

void Engine::Start()
{
  while (true)
  {
    std::vector<render_data> datas;
    for (int i = 0; i < tmpPlayers.size(); i++)
    {
      datas.push_back(tmpPlayers[i]->GetRenderData());
      tmpPlayers[i]->TickAction();
    }
  }
}