#include "../include/Game.hpp"
#include <iostream>
int main() {
    Game game;
    sf::RenderWindow window(sf::VideoMode(game.getWidth(), game.getHeight()), game.getWindowTitle(), sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    game.gameCycle(window);
    window.close();
}
