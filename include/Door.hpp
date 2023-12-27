#include "Object.hpp"

class Door : public Object {
  public:
    Door(float x, float y); 

    void update(float time);
    char getType();

};
