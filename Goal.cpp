#include "Goal.h"


Goal::Goal(): Object(19, 2) {

}

boolean Goal::intersects(Player p) {
  return (getX() == p.getX() && getY() == p.getY());
}

void Goal::move(LiquidCrystal_I2C lcd) {
  int n = random(0, 100);

  float f = n / float(100);
  if (f < 0.30) {
    if (f < 0.08)
      updateLocation(EAST);
    else if (f < 0.30)
      updateLocation(WEST);

    drawObject(lcd, GoalAppearance);
    return;
  }

  n = random(0, 100);

  f = n / float(100);
  if (f < 0.5) {
    if (f < 0.25)
      updateLocation(NORTH);
    else
      updateLocation(SOUTH);

    drawObject(lcd, GoalAppearance);
  }
}



