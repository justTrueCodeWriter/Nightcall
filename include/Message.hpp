#ifndef MESSAGE_HPP
#define MESSAGE_HPP

enum Action {
  NONE, 
  ATTACK,
  INTERACT,
  ACTIVATE,
  DIED,
  COLLIDE
};

struct Message {
  char object_type;
  Action action;
  float x = 0, y = 0;
  float width = 0, height = 0;
};
#endif
