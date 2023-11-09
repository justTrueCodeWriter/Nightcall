#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Hero {
  public:
    void render(sf::RenderWindow &window);

    float x_ = 0, y_ = 0;
    float walk_speed_ = 0.5;
    float run_speed_ = 0.1;

    sf::Texture texture;
    sf::Sprite sprite;
  private:
  
    void walk();
    void jump();
    void punch();

};
