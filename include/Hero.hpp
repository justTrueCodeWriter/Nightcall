#include "Object.hpp"

class Hero : public Object {
  public:
    Hero(float x, float y);

    void update(float time);
    char getType();

  private:
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;
    short side_ = 1;

    void move(float time, bool& isAttack);
    void jump();
    float dash(float time, bool &isAttack);

};
