#include "../include/Game.hpp"
void Game::gameCycle(sf::RenderWindow &window) {
 
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        window.close();
    }
    window.display();
  }
}
