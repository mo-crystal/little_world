#ifndef RENDER_CONTROLLER_H
#define RENDER_CONTROLLER_H

#include <vector>
#include <mutex>
#include <chrono>

#include "../basic/render_data.h"

class RenderController
{
private:
  std::vector<render_data> frame_data;
  std::mutex mtx;

public:
  RenderController(/* args */);
  ~RenderController();

  void SetFrameData(const std::vector<render_data> &a);
  void Draw();
};

#endif