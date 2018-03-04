#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "Vars.h"
#include "Object.h"

#ifndef Player_h
#define Player_h

class Player: public Object {
  public:
    Player(void);
    ~Player(void);
    boolean isAlive(void);
//    boolean reachedGoal(void);

    void setDead(boolean state);

    void updateLocation(DIRECTION dir);


  private:
    boolean alive;
};

#endif



