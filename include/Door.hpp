#include "Object.hpp"

class Door : public Object {
  public:
    Door(float x, float y); 

    void update(float time);
    void sendMessage(Message* message);
  private:
    bool isOpen = false;
    static int id_counter;
    int id = 0;

};
