#ifndef Vars_h
#define Vars_h

#define joyStickX A0
#define joyStickY A1
#define joyStickBtn 3


enum DIRECTION {
  NORTH, EAST, WEST, SOUTH
};

struct stats {
  int  wins;
  int looses;
};

#define PlayerAppearance "O"
#define ObstacleAppearance "X"
#define GoalAppearance "~"


#endif
