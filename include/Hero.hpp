#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Hero {
  public:
    sf::Texture texture;
    sf::Sprite sprite;

    Hero();

    void render(sf::RenderWindow &window);
    void move(float time);
  private:
    float x_ = 0, y_ = 0;
    float walk_speed_ = 0.5;
    float run_speed_ = 0.6;

    void jump();
    void punch();

};
