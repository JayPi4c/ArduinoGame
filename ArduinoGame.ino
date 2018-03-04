#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Player.h"
#include "Obstacle.h"
#include "Vars.h"
#include "Goal.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Player p;
Goal g;

Obstacle obstacles[4];

boolean changed = false;

boolean won;

int coolDown = 250;
unsigned long lastCoolDown = 0;
struct stats stat = {0, 0};

void setup() {
  // Notwendig, damit nicht bei jedem Start der gleiche Seed genutzt wird!
  randomSeed(analogRead(0));


  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  reset();
}

void loop() {
  if (millis() % 1000 == 0) {
    g.move(lcd);
    for (int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++) {
      obstacles[i].move(lcd);
    }
  }

  if (millis() - lastCoolDown > coolDown) {
    int JSYValue = analogRead(joyStickY);
    int JSXValue = analogRead(joyStickX);
    if (JSYValue > 1024 - 100) {
      p.updateLocation(SOUTH);
      changed = true;
    } else if (JSYValue < 100) {
      p.updateLocation(NORTH);
      changed = true;
    }
    else if (JSXValue > 1024 - 100) {
      p.updateLocation(EAST);
      changed = true;
    } else if (JSXValue < 100) {
      p.updateLocation(WEST);
      changed = true;
    }
    if (changed) {
      p.drawObject(lcd, PlayerAppearance);
      changed = false;
      lastCoolDown = millis();
    }
  }
  for (int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++) {
    if (obstacles[i].intersects(p)) {
      p.setDead(true);
    }
  }
  if (g.intersects(p)) {
    lcd.clear();
    lcd.print("You've won!");
    stat.wins++;
    won = true;
  }
  if (!p.isAlive()) {
    lcd.clear();
    lcd.print("GAME OVER!");
    stat.looses++;
  }
  //  while (!p.isAlive() || won) {
  //    //Das Spiel ist vorbei. Es muss resettet werden!
  //  }

  if (!p.isAlive()  || won) {
    lcd.setCursor(0, 1);
    String msg = "wins: ";
    msg += stat.wins;
    msg += "| looses: ";
    msg += stat.looses;
    lcd.print(msg);
    delay(3000);
    reset();
  }

}


void reset() {
  lcd.clear();
  won = false; 
  p = Player();
  g = Goal();
  p.drawObject(lcd, PlayerAppearance);
  g.drawObject(lcd, GoalAppearance);
  for (int i = 0; i < (sizeof(obstacles) / sizeof(*obstacles)); i++) {
    obstacles[i] = Obstacle(19, i);
    obstacles[i].drawObject(lcd, ObstacleAppearance);
  }
}


//wählen einer zufälligen Richtung!
//c.updateLocation(DIRECTION(random() % 4));

