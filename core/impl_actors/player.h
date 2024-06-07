#ifndef PLAYER_H
#define PLAYER_H


#include "../basic/character.h"

class Player : public Character
{
private:
  int speed = 10;

public:
  Player(Point p) : Character(p) {}
  ~Player();
  void Move();
  void TickAction() ;
};

#endif