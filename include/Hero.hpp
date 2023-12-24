#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Hero : public Object {
  public:
    Hero(float x, float y);

    void update(float time);
    void setSprite(sf::Texture texture);
    char getType();

  private:
    float x_ = 0, y_ = 0;
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    short side_ = 1;

    void move(float time);
    void jump();
    void punch();
    float dash(float time, bool &isConsistent);

};
