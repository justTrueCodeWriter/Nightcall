#include "Object.hpp"

class Button : public Object {
  public: 
    Button(float x, float y);

    void update(float time);
    char getType();
};
