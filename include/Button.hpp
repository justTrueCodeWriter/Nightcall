#include "Object.hpp"

class Button : public Object {
  public: 
    Button(float x, float y);
    ~Button();

    void update(float time);
    void sendMessage(Message* message);
  private:
    static int id_counter;
    int id = 0;
};
