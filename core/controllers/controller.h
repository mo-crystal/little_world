#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <thread>
#include<iostream>
#include <mutex>
#include <chrono>

#define NO_INTERVAL -1
#define ONCE 0

class Engine;

class Controller {
 private:
  Engine* engine;
  bool started = false;

 public:
  Controller(Engine* e) : engine(e) {}
  ~Controller();
  Engine* GetEngine() { return engine; }
  virtual void Start(double interval = ONCE) = 0;
  bool GetStarted() { return started; }
  void SetStarted() { started = true; }
};

#endif