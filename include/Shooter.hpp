#include "Object.hpp"

class Shooter : public Object {
  public:
    Shooter(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    short direction_ = 1;
    float speed = 0.2;
    float trigger_range = 300;
    bool isBulletPulled = false;
    void move(float time);
};