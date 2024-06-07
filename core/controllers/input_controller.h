#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <windows.h>
#include <vector>
#include <functional>

#include "controller.h"

#define RELEASED 0
#define PRESSED 1
#define KEY_NUMBER 256

class InputController : public Controller
{
private:
  bool keyStates[256] = {RELEASED};
  std::vector<std::function<void()>> keyPressedFunctions[KEY_NUMBER];
  std::vector<std::function<void()>> keyReleasedFunctions[KEY_NUMBER];

public:
  InputController(Engine *e) : Controller(e) {}
  ~InputController();
  void CheckKey();
  void Start(double interval);
  template <typename Func, typename... Args>
  void addFunction(int key,int state, Func &&func, Args &&...args)
  {
    auto boundFunc = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
    if(state==PRESSED){
      keyPressedFunctions[key].push_back(boundFunc);
    }else{
       keyReleasedFunctions[key].push_back(boundFunc);
    }
  }
};

#endif