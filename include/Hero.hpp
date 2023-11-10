#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Hero {
  public:
    Hero();

    sf::Sprite sprite;

    void render(sf::RenderWindow &window);
    void move(float time);
  private:
    sf::Texture texture;
    float x_ = 0, y_ = 0;
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;

    void jump();
    void punch();

};
