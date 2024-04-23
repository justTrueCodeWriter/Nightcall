#include "Object.hpp"

class Projectile : public Object {
  public:
    Projectile(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    short side_ = 1;
    float speed = 0.5;
    void move(float time);
};