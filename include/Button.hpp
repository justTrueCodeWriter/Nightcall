#include "Trigger.hpp"

class Button : public Trigger {
  public: 
    Button(float x, float y);

    void update(float time);
    void sendMessage(Message* message);
  private:
    static int id_counter;
    sf::Clock cooldown_clock;
};
