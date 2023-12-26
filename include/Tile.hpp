#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class UsualTile : public Object {
   public: 
    UsualTile(float x, float y);

    void update(float time){ return; };
    char getType();

   private:
    float x_ = 0, y_ = 0;
};
