#include "Object.hpp"

class Hero : public Object {
  public:
    Hero(float x, float y);
    ~Hero();

    void update(float time);
    char getType();
    void sendMessage(Message* msg);

  private:
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    short side_ = 1;
    bool isGround = false;

    sf::FloatRect collide_rect;

    void checkCollision();
    void move(float time, bool& isAttack);
    void jump();
    float dash(float time, bool &isAttack);

};