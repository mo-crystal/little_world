#include "render_controller.h"

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

void RenderController::Start(double interval)
{
  std::thread render_thread([&]()
                            {
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(interval));
                this->Draw();
            } });
  render_thread.detach();
}