#include "Enemy.hpp"

class Swordsman : public Enemy {
  public:
    Swordsman(float x, float y);

    void update(float time);
    void sendMessage(Message* message);

  private:
    void move(float time);
};
