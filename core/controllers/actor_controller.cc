#include "actor_controller.h"

ActorController::ActorController()
{
}

ActorController::~ActorController()
{
  for (auto i : actors)
  {
    delete i;
  }
}

void ActorController::RegisterActor(Actor *a)
{
  actors.insert(a);
}

void ActorController::TickAtion()
{
  for (auto &i : actors)
  {
    auto character = dynamic_cast<Character *>(i);
    if (character != nullptr)
    {
      character->TickAction();
    }
  }
}

std::vector<render_data> ActorController::GetRenderData()
{
  std::vector<render_data> res;
  for (auto i : actors)
  {
    auto renderableActor = dynamic_cast<RenderableActor *>(i);
    if (renderableActor != nullptr)
    {
      res.push_back(renderableActor->GetRenderData());
    }
  }
  std::sort(res.begin(), res.end(), [](const render_data &a, const render_data &b)
            { return a.p.get_y() < b.p.get_y(); });
  return res;
}