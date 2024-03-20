#include "Object.hpp"

class UsualSpikes : public Object {
  public:
    UsualSpikes(float x, float y);
    ~UsualSpikes();
    char getType();
    void update(float time);
    void sendMessage(Message* msg);
};
