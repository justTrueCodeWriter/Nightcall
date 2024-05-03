#include "Object.hpp"

class Projectile : public Object {
  public:
    Projectile(float x, float y, short direction);

    void update(float time);
    void sendMessage(Message* message);

  private:
    short direction_ = 1;
    float speed = 0.5;
    void move(float time);
};