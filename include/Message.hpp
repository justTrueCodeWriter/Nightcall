#ifndef MESSAGE_HPP
#define MESSAGE_HPP

class Object;

enum Action {
  ACTIVATE, // DOOR/TRAP
  ATTACK, 
  DIED,
  INTERACT,// WITH BUTTON/TILE
  MOVE,
  COLLIDE
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
      int direction;
      float dmg;
    } attack;
    struct {
      Object *who;
    } died;
    struct {
    } interact;
    struct {
    } move;
    struct {
      Direction direction;
    } collide;
  };
};
#endif