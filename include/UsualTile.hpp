#ifndef USUALTILE_HPP
#define USUALTILE_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class UsualTile : public Object {
   public: 
    UsualTile(float x, float y);
    ~UsualTile();

    void update(float time){};
    void sendMessage(Message* message);
};
#endif