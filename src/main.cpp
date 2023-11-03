#include "../include/Game.hpp"

int main() {
    Game game;
    sf::RenderWindow window(sf::VideoMode(game.getWidth(), game.getHeight()), game.getWindowTitle(), sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    game.gameCycle(window);
}