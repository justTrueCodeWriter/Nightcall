#include "../include/Menu.hpp"

void Menu::startGame() {
  sf::RenderWindow window(sf::VideoMode(getWidth(), getHeight()), getWindowTitle(), sf::Style::Fullscreen);
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  Game::getInstance().gameCycle(window);
  window.close();
}
