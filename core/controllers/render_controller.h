#ifndef RENDER_CONTROLLER_H
#define RENDER_CONTROLLER_H

#include <vector>
#include <mutex>
#include <chrono>

#include "controller.h"
#include "../basic/render_data.h"

class RenderController:public Controller
{
private:
  std::vector<render_data> frame_data;
  std::mutex mtx;

public:
  RenderController(Engine * e):Controller(e){}
  ~RenderController();

  void SetFrameData(const std::vector<render_data> &a);
  void Draw();
  void Start(double interval);
};

#endif