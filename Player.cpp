#include "Player.h"

Player::Player(void): Object(0, 1) {
  alive = true;
}
Player::~Player(void) {

}

void Player::setDead(boolean state) {
  alive = !state;
}

//boolean Player::reachedGoal() {
//  return getX() == 19;
//}



boolean Player::isAlive(void) {
  return alive;
}


void Player::updateLocation(DIRECTION dir) {
  px = x;
  py = y;
  switch (dir) {
    case NORTH:
      y--;
      if (y < 0) {
        y = 3;
      }
      break;
    case WEST:
      x--;
      if (x < 0) {
        x = 0;
      }
      break;
    case SOUTH:
      y = (y + 1) % 4;
      break;
    case EAST:
      x = (x + 1) % 20;
      break;
    default:
      x = 0;
      y = 1;
      break;
  }
}




