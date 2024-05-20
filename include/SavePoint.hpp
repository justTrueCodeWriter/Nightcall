#include "Object.hpp"

class SavePoint : public Object {
  public: 
    SavePoint(float x, float y);

    void update(float time);
    void sendMessage(Message* message);
};
