#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "Vars.h"

#ifndef Object_h
#define Object_h

class Object {
  public:
  Object();
    Object(int x_, int y_);  //Konstruktor
    ~Object(void); //Destruktor

    int getX(void);
    int getY(void);
    void updateLocation(DIRECTION dir);

    void drawObject(LiquidCrystal_I2C lcd);


  protected:
    int x;
    int y;
    int px;
    int py;
};

#endif



