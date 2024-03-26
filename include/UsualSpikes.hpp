#include "Object.hpp"

class UsualSpikes : public Object {
  public:
    UsualSpikes(float x, float y);
    ~UsualSpikes();
    void update(float time);
    void sendMessage(Message* message);
};
