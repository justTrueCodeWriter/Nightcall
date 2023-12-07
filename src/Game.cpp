#include "../include/Game.hpp"
#include "../include/Hero.hpp"

void Game::Level::initMap(int level_number) {
  objects = new Object*[1];
  objects[0] = new Hero;
}

void Game::Level::deInitMap() {
}

void Game::Level::initObjects(int level_number) {
}

void Game::Level::deInitObjects() {
}

void Game::gameCycle(sf::RenderWindow &window) {


  sf::Clock clock;

  Level level;
  level.initMap(1);

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asMilliseconds();
    clock.restart();
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        return;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        return;
    } 

    level.objects[0]->load(time);

    window.clear(sf::Color::White);  
    window.draw(level.objects[0]->getSprite());
    window.display();
  }
}
