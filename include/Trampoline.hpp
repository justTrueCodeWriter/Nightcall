#include "Object.hpp"

class Trampoline : public Object {
  public:
    Trampoline(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

};