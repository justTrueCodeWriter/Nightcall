#include "Object.hpp"
#include <SFML/System/Clock.hpp>

class Projectile : public Object {
  public:
    Projectile(float x, float y, short direction);

    void update(float time);
    void sendMessage(Message* message);

  private:
    short direction_ = 1;
    float speed = 0.5;
    sf::Clock life_clock;
    void move(float time);
};