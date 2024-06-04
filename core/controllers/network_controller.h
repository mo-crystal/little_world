#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include"controller.h"

class NetworkController:public Controller
{
private:
  /* data */
public:
  NetworkController(Engine * e):Controller(e){}
  ~NetworkController();
};



#endif