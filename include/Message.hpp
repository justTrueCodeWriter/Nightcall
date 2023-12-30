#ifndef MESSAGE_HPP
#define MESSAGE_HPP

enum Action {
  ATTACK,
  INTERACT,
  ACTIVATE
};

struct Message {
  char object_type;
  Action action;
  float x, y;
};
#endif
