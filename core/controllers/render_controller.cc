#include "render_controller.h"

RenderController::RenderController(/* args */)
{
}

RenderController::~RenderController()
{
}

void RenderController::SetFrameData(const std::vector<render_data> &a)
{
  std::lock_guard<std::mutex> lock(mtx); 
  frame_data = a;
}

void RenderController::Draw()
{
  std::lock_guard<std::mutex> lock(mtx);
  
}