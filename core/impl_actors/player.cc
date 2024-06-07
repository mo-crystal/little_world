#include "player.h"

#include <cstdlib>
#include <ctime>

Player::~Player()
{
}

void Player::Move()
{

  std::string now_state = this->GetNowState();
  
  srand(time(nullptr));

  int random_number = rand() % 4;
  Point p;
  switch (random_number)
  {
  case 0:
    p = this->GetLocation() + Point(speed, 0);
    break;
  case 1:
    p = this->GetLocation() + Point(0, speed);
    break;
  case 2:
    p = this->GetLocation() + Point(-speed, 0);
    break;
  case 3:
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
