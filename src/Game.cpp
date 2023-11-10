#include "../include/Game.hpp"
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
        window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        window.close();
    } 

    hero.move(time);

    window.clear(sf::Color::White);  
    window.draw(hero.sprite);
    window.display();
  }
}
