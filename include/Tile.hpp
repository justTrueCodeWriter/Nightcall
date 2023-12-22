#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Tile : public Object {
   public: 
    Tile(float x, float y);

    void sendMessage(); 
    void getMessage();
    void update(float time){ return; };
    void setSprite(sf::Texture texture);
    sf::Sprite getSprite();

   private:
    float x_ = 0, y_ = 0;
    sf::Sprite sprite;
};
