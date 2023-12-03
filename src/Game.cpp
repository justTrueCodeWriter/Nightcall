#include "../include/Game.hpp"
#include "../include/Level.hpp"
void Game::gameCycle(sf::RenderWindow &window) {

  Map* map = new Map; 

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

    map->hero.move(time);

    window.clear(sf::Color::White);  
    window.draw(map->hero.sprite);
    window.display();
  }
}
