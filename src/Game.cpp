#include "../include/Game.hpp"

void Game::Level::initMap(int level_number) {
}

void Game::Level::deInitMap() {
}

void Game::Level::initObjects(int level_number) {
}

void Game::Level::deInitObjects() {
}

void Game::gameCycle(sf::RenderWindow &window) {


  sf::Clock clock;


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

    //map->hero.move(time);

    window.clear(sf::Color::White);  
    //window.draw(map->hero.sprite);
    window.display();
  }
}
