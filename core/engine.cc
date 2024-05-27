#include "engine.h"

Engine::Engine(int side, std::string _mode)
{
  mode = _mode;
  actorcontroller = new ActorController;
  rendercontroller = new RenderController;
}

Engine::~Engine()
{
  delete actorcontroller;
  delete rendercontroller;
}

void Engine::Init()
{
  Point a(480, 320);
  Player *p = new Player(a);
  p->InitStates("D:\\CODE\\C++\\civilization\\src\\client\\res\\game\\c1");
  actorcontroller->RegisterActor(p);
}

void Engine::Start()
{
  std::thread render_thread([this]()
                            {
            while (1)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(TickTime));
                rendercontroller->Draw();
            } });
  render_thread.detach();
  while (true)
  {
    std::vector<render_data> datas = actorcontroller->GetRenderData();
    rendercontroller->SetFrameData(datas);
    std::this_thread::sleep_for(std::chrono::duration<double>(TickTime));
    actorcontroller->TickAtion();
  }
}