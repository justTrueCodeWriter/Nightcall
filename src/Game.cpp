#include "../include/Game.hpp"
#include "../include/Hero.hpp"

void Game::Level::initMap(int level_number) {
}

void Game::Level::deInitMap() {
}

void Game::Level::initObjects(int level_number) {
  objects = new Object*[1];
  objects[0] = new Hero;
}

void Game::Level::deInitObjects() {
}

void Game::gameCycle(sf::RenderWindow &window) {


  sf::Clock clock;

  Level level;
  level.initObjects(1);

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

    for (int i = 0; i < sizeof(level.objects)/sizeof(level.objects[0]); i++) 
      level.objects[i]->update(time);

    window.clear(sf::Color::White);  
    for (int i = 0; i < sizeof(level.objects)/sizeof(level.objects[0]); i++) 
      window.draw(level.objects[i]->getSprite());
    window.display();
  }
}
