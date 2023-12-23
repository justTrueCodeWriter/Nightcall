#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/Tile.hpp"
#include <iostream>
#include <string.h>

void Game::Level::initMap() {
  std::vector<std::string> map = {
                      "===============================================================",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=  H                                                          =",
                      "=                                                             =",
                      "==============================================================="
                    }; 

  map_mask.swap(map);
}

std::vector<std::string>* Game::Level::getMapMask() { return &map_mask; }

void Game::Level::deInitMap() {
  map_mask.clear();
}

int Game::initObjects() {
  static int objects_counter = 0;
  level.initMap();
  std::vector<std::string> map_mask = *level.getMapMask();

  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 63; j++) {
      if (map_mask[i][j] == 'H') {
        hero_index = objects_counter;
        objects.push_back(new Hero(j*30, i*30));
        objects.back()->setSprite(*resource_manager->getTexture(map_mask[i][j]));
      }
      else if (map_mask[i][j] == '=') {
        objects.push_back(new Tile(j*30, i*30));
        objects.back()->setSprite(*resource_manager->getTexture(map_mask[i][j]));
        objects_counter++;
      }
    }
  }
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

void Game::deInitObjects() {
  objects.clear();
}

void Game::gameCycle(sf::RenderWindow &window) {

  resource_manager = new ResourceManager;

  resource_manager->loadTextures();
  sf::Sprite backgroundSprite(*resource_manager->getTexture('B'));
  backgroundSprite.setScale(1.7, 1.7);

  sf::Clock clock;
  
  int objects_amount = initObjects();

  sf::View Camera(sf::FloatRect(0, 0, 600, 300));

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asMilliseconds();
    clock.restart();
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        deInitObjects();
        return;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        deInitObjects();
        return;
      }
    } 

    Camera.setCenter(objects[hero_index]->getSprite().getPosition());


    for (int i = 0; i < objects_amount; i++) {
      objects[i]->update(time);
    }

    for (int i = 0; i < objects_amount; i++) {
      if (i != hero_index) {
        if (objects[i]->getSprite().getGlobalBounds().intersects(objects[hero_index]->getSprite().getGlobalBounds()) == true) {
          std::cout << "intersects" << std::endl;
        }
      }
    }

    //window.setView(Camera);
    window.clear(sf::Color::White);  
    window.draw(backgroundSprite);
    for (int i = 0; i < objects_amount; i++) 
      window.draw(objects[i]->getSprite());
    window.display();
  }
}
