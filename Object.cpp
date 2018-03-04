#include "Object.h"


Object::Object() {

}


Object::Object(int x_, int y_) {
  x = x_;
  y = y_;
  px = x;
  py = y;
}

Object::~Object(void) {

}


int Object::getX(void) {
  return x;
}

int Object::getY(void) {
  return y;
}

void Object::updateLocation(DIRECTION dir) {
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
        x = 19;
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






void Object::drawObject(LiquidCrystal_I2C lcd, String appearance) {
  lcd.setCursor(px, py);
  lcd.print(" ");
  lcd.setCursor(x, y);
  lcd.print(appearance);
}





