#include "Message.hpp"
#include "Object.hpp"

class Hero : public Object{
  public:
    Hero(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    float jump_multiplier = 0.9;
    short direction_ = 1;
    bool isAttack = false;
    bool isJump = false;
    sf::Clock jump_clock;


    Direction collide_side = NONE;

    void move(float time);
    void jump(float time);
    float dash(float time);

};
