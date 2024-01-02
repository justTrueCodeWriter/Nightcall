#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class UsualTile : public Object {
   public: 
    UsualTile(float x, float y);

    void update(float time);
    char getType();
};
