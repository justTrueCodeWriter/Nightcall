#include "../include/Menu.hpp"
#include "../include/ResourceManager.hpp"

enum MenuChoice {START, EXIT};

void Menu::menuLoop() {

  MenuChoice menu_choice = START;

  sf::RenderWindow window(sf::VideoMode(getWidth(), getHeight()), getWindowTitle(), sf::Style::Fullscreen);
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  sf::Sprite backgroundSprite(*ResourceManager::getInstance().getTexture('M'));
  backgroundSprite.scale(1.8, 1.5);

  sf::Font font;
  font.loadFromFile("media/fonts/Rubik_Glitch/RubikGlitch-Regular.ttf");

  sf::Text text_start, text_exit;
  text_start.setString("Start");
  text_exit.setString("Exit");

  text_start.setFont(font);
  text_start.setCharacterSize(100);
  text_start.setPosition(width_/2.3, height_/2.0);
  text_start.setFillColor(sf::Color::White);

  text_exit.setFont(font);
  text_exit.setCharacterSize(100);
  text_exit.setPosition(width_/2.2, height_/1.5);
  text_exit.setFillColor(sf::Color::White);

  while (window.isOpen()) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
      text_start.setStyle(sf::Text::Bold); 
      text_exit.setStyle(sf::Text::Regular); 
      menu_choice = START; 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { 
      text_exit.setStyle(sf::Text::Bold); 
      text_start.setStyle(sf::Text::Regular); 
      menu_choice = EXIT;
    }


    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        return;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return; }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        switch (menu_choice) {
          case START:
            Game::getInstance().gameLoop(window);
            break;
          case EXIT:
            return;           
            break;
        }
      }
    } 
    
    window.clear(sf::Color::Black);  
    window.draw(backgroundSprite);
    window.draw(text_start);
    window.draw(text_exit);
    window.display();
  }
  window.close();
}
