#include "Object.hpp"

class Swordsman : public Object {
  public:
    Swordsman(float x, float y);

    void update(float time);
    char getType();

  private:
    short side_ = 1;
    void move(float time);
};
