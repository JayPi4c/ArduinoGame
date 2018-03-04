#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "Vars.h"
#include "Object.h"
#include "Player.h"

#ifndef Obstacle_h
#define Obstacle_h

class Obstacle: public Object {
  public:
    Obstacle();
    Obstacle(int x_, int y_);
    boolean intersects(Player p);
    void move(LiquidCrystal_I2C lcd);
};

#endif


