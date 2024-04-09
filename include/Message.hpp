#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "SFML/Graphics.hpp"

class Object;

enum Action {
  ACTIVATE, // DOOR/TRAP
  ATTACK, 
  DIED,
  INTERACT,// WITH BUTTON/TILE
  MOVE
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
  };
};
#endif