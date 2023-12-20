#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Tile : public Object {
   public: 
    Tile(float x, float y, sf::Texture texture);
    void update(float time){ return; };
    sf::Sprite getSprite();

   private:
    float x_ = 0, y_ = 0;
    sf::Sprite sprite;
};
