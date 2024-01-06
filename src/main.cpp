#include "../include/Menu.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    Menu menu;
    sf::Music music;
    music.openFromFile("media/music/background_music.wav");
    music.setLoop(true);
    //music.play();
    menu.menuLoop();

}
