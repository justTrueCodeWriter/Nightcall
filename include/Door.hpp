#include "Object.hpp"

class Door : public Object {
  public:
    Door(float x, float y); 
    ~Door();

    void update(float time);
    char getType();
  private:
    bool isOpen = false;

};
