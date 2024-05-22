#ifndef MESSAGE_HPP
#define MESSAGE_HPP

class Object;

enum Action {
  ACTIVATE, // DOOR/TRAP
  ATTACK, 
  DIED,
  INTERACT,// WITH BUTTON/TILE
  MOVE,
  COLLIDE,
  SAVE

};

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NONE
};

struct Message {
  Message(){};
  Action action;
	Object* sender;
  union {
    struct {
      int id = 0;
    } activate;
    struct {
      Object *who;
    } died;
    struct {
      Direction direction;
    } collide;
  };
};
#endif