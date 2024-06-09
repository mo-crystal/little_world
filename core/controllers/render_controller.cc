#include "render_controller.h"
#include "../engine.h"

RenderController::~RenderController()
{
}

void RenderController::SetFrameData(const std::vector<render_data> &a)
{
  frame_data = a;
}

void RenderController::Draw()
{
    for (int i = 0; i < frame_data.size(); i++) {
    std::cout << "在点" << frame_data[i].p.get_x() << ","
              << frame_data[i].p.get_y() << "画" << frame_data[i].resourceId
              << std::endl;
  }
}

void RenderController::Start(double interval)
{
  std::cout <<"started"<<std::endl;
  std::thread render_thread([&,interval]()
                            {
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(interval));
                ActorController* act_ctrl = dynamic_cast<ActorController*>(this->GetEngine()->GetController("actorcontroller"));
              if (act_ctrl) {
                this->SetFrameData(act_ctrl->GetRenderData());  
              } 
                this->Draw();
            } });
  render_thread.detach();
  this->SetStarted();
}