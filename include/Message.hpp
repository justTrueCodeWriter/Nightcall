#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "SFML/Graphics.hpp"

class Object;

enum Action {
  NONE, 
  ATTACK,
  INTERACT,
  ACTIVATE,
  DIED,
  COLLIDE,
  MOVE
};

struct Message {
  char object_type;
  Action action;
  union {
    struct {
      Object *who;
    } died;
    struct {
      int direction;
      float dmg;
    } attack;
  };
  sf::FloatRect sprite_rect;
	Object* sender;
};
#endif