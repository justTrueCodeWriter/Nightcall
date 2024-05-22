#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"
#include <SFML/System/Clock.hpp>

class Enemy : public Object {
    protected:
     short direction_ = 1;
     float speed = 0;
     sf::Clock direction_clock;
};
#endif