#include "Object.hpp"

class Swordsman : public Object {
  public:
    Swordsman(float x, float y);
    ~Swordsman();

    void update(float time);
    char getType();

  private:
    short side_ = 1;
    float speed = 0.5;
    void move(float time);
};
