#include "Enemy.hpp"
#include <SFML/System/Clock.hpp>

class Shooter : public Enemy {
  public:
    Shooter(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    float trigger_range = 300;
    bool isBulletPulled = false;
    sf::Clock cooldown_clock;
    void move(float time);
};