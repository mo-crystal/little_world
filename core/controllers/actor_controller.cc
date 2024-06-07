#include "actor_controller.h"

ActorController::~ActorController()
{
  for (auto i : actors)
  {
    delete i.second;
  }
}

void ActorController::RegisterActor(std::string name, Actor *a)
{
  if (actors.find(name) == actors.end())
  {
    actors[name] = a;
  }
}

void ActorController::TickAtion()
{
  std::lock_guard<std::mutex> lock(mtx);
  for (auto &i : actors)
  {
    auto character = dynamic_cast<Character *>(i.second);
    if (character != nullptr)
    {
      character->TickAction();
    }
  }
}

std::vector<render_data> ActorController::GetRenderData()
{
  
  std::vector<render_data> res;
  {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto i : actors)
    {
      auto renderableActor = dynamic_cast<RenderableActor *>(i.second);
      if (renderableActor != nullptr)
      {
        res.push_back(renderableActor->GetRenderData());
        renderableActor->NextFrame();
      }
    }
  }
  std::sort(res.begin(), res.end(), [](const render_data &a, const render_data &b)
            { return a.p.get_y() < b.p.get_y(); });
  return res;
}

void ActorController::Start(double interval)
{
  std::cout << "started" << std::endl;
  std::thread render_thread([&]()
                            {
            while (true)
            {
              std::this_thread::sleep_for(std::chrono::duration<double>(interval));
              this->TickAtion();
            } });
  render_thread.detach();
  this->SetStarted();
}

void ActorController::UpdateActorByName(std::string name, std::string state)
{
  if (actors.find(name) != actors.end())
  { // TODO:状态map上移至actor保证无贴图actor也有执行状态
    auto renderableActor = dynamic_cast<RenderableActor *>(actors[name]);
    if (renderableActor != nullptr)
    {
      renderableActor->StateChange(state);
    }
  }
}