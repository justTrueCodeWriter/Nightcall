#include "../include/Game.hpp"
void Game::gameCycle() {
    sf::RenderWindow window(sf::VideoMode(getWidth(), getHeight()), getWindowTitle(), sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    int count = 0;
    while (count <= 30) {
        window.display();
        count++;
    }
}
