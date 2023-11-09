#include "../include/Game.hpp"
void Game::gameCycle(sf::RenderWindow &window) {
 
  sf::Clock clock;
  float current_frame = 0;

  hero.texture.loadFromFile("media/img/Fifteen.png");
  hero.sprite.setTexture(hero.texture);
  hero.sprite.setPosition(50, 100);
  hero.sprite.setScale(2, 2);

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      hero.sprite.move(-hero.walk_speed_*time, 0); 
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame -= 8;
      hero.sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      hero.sprite.move(hero.walk_speed_*time, 0); 
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame -= 8;
      hero.sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 43));
    }
    else {
      current_frame += 0.01*time;
      if (current_frame > 12) current_frame -= 12;
      hero.sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 42));
    }


    window.clear(sf::Color::White);  
    window.draw(hero.sprite);
    window.display();
  }
}
