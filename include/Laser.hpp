#include "Object.hpp"

class Laser : public Object {
  public:
    Laser(float x, float y);
    ~Laser();
    void update(float time);
    void sendMessage(Message* message);
};
