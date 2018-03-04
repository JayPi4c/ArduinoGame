#include "Obstacle.h"

Obstacle::Obstacle() {

}
Obstacle::Obstacle(int x_, int y_): Object(x_, y_) {

}

boolean Obstacle::intersects(Player p) {
  return (getX() == p.getX() && getY() == p.getY());
}

void Obstacle::move(LiquidCrystal_I2C lcd) {
  int n = random(0, 100);

  float f = n / float(100);
  if (f < 0.5) {
    updateLocation(WEST);
    drawObject(lcd, ObstacleAppearance);
  }
}



