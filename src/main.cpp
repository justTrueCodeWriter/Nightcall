#include "../include/Game.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    Game game;
    sf::Music music;
    music.openFromFile("media/music/background_music.wav");
    music.setLoop(true);
    //music.play();

    sf::RenderWindow window(sf::VideoMode(game.getWidth(), game.getHeight()), game.getWindowTitle(), sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    game.gameCycle(window);
    window.close();
}
