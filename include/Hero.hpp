#include "Object.hpp"

class Hero : public Object {
  public:
    Hero(float x, float y);
    ~Hero();

    void update(float time);
    void sendMessage(Message* message);

  private:
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    short side_ = 1;
    bool isGround = false;
    bool isAttack = false;

    sf::FloatRect collide_rect;

    void move(float time);
    void jump();
    float dash(float time);

};
