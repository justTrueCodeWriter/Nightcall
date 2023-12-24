#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Tile : public Object {
   public: 
    Tile(float x, float y);

    void update(float time){ return; };
    void setSprite(sf::Texture texture);
    char getType();

   private:
    float x_ = 0, y_ = 0;
};
