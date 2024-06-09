#ifndef PLAYER_H
#define PLAYER_H

#include "../basic/character.h"

class Player : public Character
{
private:
  double speed = 0;
  double maxspeed = 100;

public:
  Player(Point p) : Character(p) {}
  ~Player();
  void Move();
  void TickAction();
  void SetSpeed(double _speed);
  double GetMaxSpeed() { return maxspeed; }
  void SetMaxSpeed(double _speed) { maxspeed = _speed; }
  double GetSpeed() { return speed; }
};

#endif