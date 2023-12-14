#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Hero : public Object {
  public:
    Hero();

    sf::Sprite sprite;

    void update(float time);
    sf::Sprite getSprite();

    void move(float time);
  private:
    sf::Texture texture;
    float x_ = 0, y_ = 0;
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    short side_ = 1;

    void jump();
    void punch();
    float dash(float time, bool &isConsistent);

};
