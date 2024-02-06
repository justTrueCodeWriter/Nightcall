#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "SFML/Graphics.hpp"

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
  //float x = 0, y = 0;
  //float width = 0, height = 0;
  sf::FloatRect sprite_rect;
};
#endif
