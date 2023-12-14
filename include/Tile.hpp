#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Tile : public Object {
   public: 
    void update(float time){};
    sf::Sprite getSprite(){ return sf::Sprite(); };
};
