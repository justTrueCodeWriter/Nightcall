#include "Object.hpp"

class Button : public Object {
  public: 
    Button(float x, float y);
    ~Button();

    void update(float time);
    char getType();
};
