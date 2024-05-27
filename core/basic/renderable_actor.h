#ifndef RENDERABLE_ACTOR_H
#define RENDERABLE_ACTOR_H

#include <iostream>
#include <unordered_map>
#include <filesystem>
#include <regex>
#include <algorithm>
#include <windows.h>

#include "actor.h"
#include "render_data.h"

class RenderableActor : public Actor
{
private:
  std::unordered_map<std::string, std::vector<std::string>> States;
  std::string now_state = "";
  std::string default_state = "";
  int nowframe = 0;

public:
  RenderableActor(Point p, double scale = 1) : Actor(p, scale) {}
  void SetDefaultState(const std::string &s_name);
  bool StateChange(const std::string &s_name);
  void InitStates(const std::string &path);

  void TickAction() override;
  render_data GetRenderData();

  virtual ~RenderableActor();
};

#endif