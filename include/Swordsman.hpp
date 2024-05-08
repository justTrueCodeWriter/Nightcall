#include "Object.hpp"

class Swordsman : public Object {
  public:
    Swordsman(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    short direction_ = 1;
    float speed = 0.5;
    void move(float time);
};
