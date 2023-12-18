#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/Tile.hpp"
#include <iostream>
#include <string.h>

void Game::Level::initMap(int level_number) {
  char *map[30] = {
                      "================================================================",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "=                                                              =",
                      "================================================================"
                    }; 
  map_mask = map;  
  
}

void Game::Level::createMapByMask() {
  int map_h = sizeof(**map_mask)/sizeof(*map_mask);
  int map_w = sizeof(map_mask[0])/sizeof(char);
  for (int i = 0; i < map_h; i++) {
    for (int j = 0; j < map_w; j++) {
     if (map_mask[i][j] == '=') {
       objects.push_back(new Tile(j*32, i*32));
     }
    }
  }
}

void Game::Level::deInitMap() {
  delete [] map_mask;
}

int Game::Level::initObjects(int level_number) {
  objects.push_back(new Hero);
  createMapByMask();
  /*
  int map_w = sizeof(map_mask[0])/sizeof(char);
  int entrances_count = 0;
  for (int i = 0; i < possible_objects.size(); i++) {
    for (int j = 0; j < map_w; j++) {
      if (strchr(map_mask[j], possible_objects[i])) {
       entrances_count++;
      }
    }
    if (entrances_count) {}
  }*/

  return objects.size();
}

void Game::Level::deInitObjects() {
  objects.clear();
}

void Game::gameCycle(sf::RenderWindow &window) {

  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("media/img/background.png");
  sf::Sprite backgroundSprite(backgroundTexture);
  backgroundSprite.setScale(1.7, 1.7);

  sf::Clock clock;

  Level level;
  int objects_amount = level.initObjects(1);
  std::cout << objects_amount << std::endl;

  sf::View Camera(sf::FloatRect(0, 0, 400, 400));

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asMilliseconds();
    clock.restart();
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        level.deInitObjects();
        return;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        level.deInitObjects();
        return;
      }
    } 

    Camera.setCenter(level.objects[0]->getSprite().getPosition());

    for (int i = 0; i < objects_amount; i++) 
        level.objects[i]->update(time);
    }

    window.setView(Camera);
    window.clear(sf::Color::White);  
    window.draw(backgroundSprite);
    /*for (int i = 0; i < objects_amount; i++) 
      window.draw(level.objects[i]->getSprite());
      */
    window.display();
}
