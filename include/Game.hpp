#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "../include/Hero.hpp"

class Game
{
  public:
    int getWidth() {
      return width_;
    }
    int getHeight() {
      return height_;
    }
    std::string getWindowTitle() {
      return window_title_;
    }
    void gameCycle(sf::RenderWindow &window);

  private:
    int width_ = 1920, height_ = 1080;

    Hero hero;

    std::string window_title_ = "Nighcall";
};
