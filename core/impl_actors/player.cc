#include "player.h"

#include <cstdlib>
#include <ctime>

Player::~Player()
{
}

void Player::Move()
{
  std::string now_state = this->GetNowState();
  Point p;
  switch (this->GetTowards())
  {
  case EAST:
    p = this->GetLocation() + Point(speed, 0);
    break;
  case NORTH:
    p = this->GetLocation() + Point(0, speed);
    break;
  case WEST:
    p = this->GetLocation() + Point(-speed, 0);
    break;
  case SOUTH:
    p = this->GetLocation() + Point(0, -speed);
    break;
  default:
    break;
  }
  this->SetLocation(p);
}

void Player::TickAction()
{
  Move();
}

void Player::SetSpeed(double _speed)
{
  if (speed == _speed)
  {
    return;
  }
  speed = _speed;
  if (speed == 0)
  {
    this->StateChange("idle");
  }
  else
  {
    this->StateChange("walk");
  }
}