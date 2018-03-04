#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "Vars.h"
#include "Object.h"
#include "Player.h"

#ifndef Goal_h
#define Goal_h

class Goal: public Object {
  public:
    Goal();
    boolean intersects(Player p);
    void move(LiquidCrystal_I2C lcd);
};

#endif


