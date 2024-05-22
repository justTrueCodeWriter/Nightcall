#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"

class Enemy : public Object {
    protected:
     short direction_ = 1;
     float speed = 0;
};
#endif