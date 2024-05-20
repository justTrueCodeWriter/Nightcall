#include "Object.hpp"

class AutomaticSpikes : public Object {
  public:
    AutomaticSpikes(float x, float y);
    void update(float time);
    void sendMessage(Message* message);

  private:
    bool isActive = false;
    bool isAlreadyActivated = false;
    static int id_counter;
    int id = 0;
};
