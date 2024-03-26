#include "Object.hpp"

class Door : public Object {
  public:
    Door(float x, float y); 
    ~Door();

    void update(float time);
    void sendMessage(Message* message);
  private:
    bool isOpen = false;

};
