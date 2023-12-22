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
                      "=                                                             =",
                      "=  H                                                          =",
                      "==============================================================="
                    }; 

  std::cout << "correct in initMap" << std::endl;
  std::cout << map[10] << std::endl;
  map_mask.swap(map);
}

std::vector<std::string>* Game::Level::getMapMask() { return &map_mask; }

void Game::Level::deInitMap() {
  map_mask.clear();
}

int Game::initObjects() {
  level.initMap();
  std::vector<std::string> map_mask = *level.getMapMask();

  std::cout << map_mask[10] << std::endl;

  std::cout << "correct in initObjects" << std::endl;

  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 64; j++) {
      if (map_mask[i][j] == 'H') {
        objects.push_back(new Hero(i*30, j*30));
        objects[objects.capacity()-1]->setSprite(*resource_manager->getTexture(map_mask[i][j]));
      }
      else if (map_mask[i][j] == '=') {
        objects.push_back(new Tile(j*30, i*30));
        objects[objects.capacity()-1]->setSprite(*resource_manager->getTexture(map_mask[i][j]));
      }
    }
  }
  std::cout << "correct out initObjects" << std::endl;
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
  std::cout << resource_manager->textures.data() << std::endl;
  sf::Sprite backgroundSprite(*resource_manager->getTexture('B'));
  backgroundSprite.setScale(1.7, 1.7);

  sf::Clock clock;
  
  int objects_amount = initObjects();
  std::cout << objects_amount << std::endl;

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

    Camera.setCenter(objects[0]->getSprite().getPosition());

    for (int i = 0; i < objects_amount; i++) {
        objects[i]->update(time);
    }

    //window.setView(Camera);
    window.clear(sf::Color::White);  
    window.draw(backgroundSprite);
    for (int i = 0; i < objects_amount; i++) 
      window.draw(objects[i]->getSprite());
    window.display();
  }
}
