#include "Object.hpp"

class Trigger : public Object {
  public: 
    Trigger(float x, float y);

    void update(float time);
    void sendMessage(Message* message);
  private:
    static int id_counter;
    int id = 0;
};
