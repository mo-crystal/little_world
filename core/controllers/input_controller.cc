#include "input_controller.h"

InputController::~InputController()
{
}

void InputController::CheckKey()
{
  for (int i = 0; i < 256; i++)
  {
    bool currentState = (GetAsyncKeyState(i) & 0x8000) != 0;
    if (currentState && !keyStates[i])
    {

    }
    else if (!currentState && keyStates[i])
    {
      
    }
    keyStates[i] = currentState;
  }
}

void InputController::Start(double interval)
{
  std::thread render_thread([&]()
                            {
            while (true)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(interval));
                this->CheckKey();
            } });
  render_thread.detach();
}
