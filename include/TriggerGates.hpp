#include "Trigger.hpp"

class TriggerGates : public Trigger {
  public: 
    TriggerGates(float x, float y);

    void update(float time);
    void sendMessage(Message* message);
  private:
    static int id_counter;
};
