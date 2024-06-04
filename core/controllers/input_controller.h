#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <windows.h>

#include "controller.h"

class InputController : public Controller
{
private:
  bool keyStates[256] = {0};

public:
  InputController(Engine *e) : Controller(e) {}
  ~InputController();
  void CheckKey();
  void Start(double interval);
};

#endif