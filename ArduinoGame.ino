#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Player.h"
#include "Obstacle.h"
#include "Vars.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Player p;

Obstacle obstacles[4];

boolean changed = false;

boolean won = false;

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();

  p.drawPlayer(lcd);
  for (int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++) {
    obstacles[i] = Obstacle(19, i);
    obstacles[i].drawObject(lcd);
  }
}

void loop() {
  if(millis() % 1000 == 0){
for(int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++){
  obstacles[i].move(lcd);
}
  }

  
  int JSYValue = analogRead(joyStickY);
  int JSXValue = analogRead(joyStickX);
  if (JSYValue > 1024 - 100) {
    p.updateLocation(SOUTH);
    changed = true;
  } else if (JSYValue < 100) {
    p.updateLocation(NORTH);
    changed = true;
  }
  if (JSXValue > 1024 - 100) {
    p.updateLocation(EAST);
    changed = true;
  } else if (JSXValue < 100) {
    p.updateLocation(WEST);
    changed = true;
  }
  if (changed) {
    p.drawPlayer(lcd);
    changed = false;
    delay(250);
  }
for(int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++){
  if(obstacles[i].intersects(p)){
    p.setDead(true);
    }
  }
  if(p.reachedGoal()){
    lcd.clear();
    lcd.print("You've won!");
    won = true;
    }
  if(!p.isAlive()){
    lcd.clear();
    lcd.print("GAME OVER!");
    }
  while(!p.isAlive() || won){
    //Das Spiel ist vorbei. Es muss resettet werden!
    }
 
}


//wählen einer zufälligen Richtung!
//c.updateLocation(DIRECTION(random() % 4));

