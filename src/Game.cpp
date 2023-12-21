#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/Tile.hpp"
#include <iostream>
#include <string.h>

void Game::Level::initMap(int level_number) {

  std::cout << map_mask[0][1] << std::endl;

  /*
  map_mask.push_back("================================================================");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("=                                                              =");
  map_mask.push_back("================================================================");
  */

}

void Game::Level::createObjectsByMask() {
  //int map_h = sizeof(map_mask)/sizeof(map_mask[0]);
  //int map_w = map_mask[0].capacity();
  std::string map[35] = {
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
  map_mask = map;  

  std::cout << "correct load" << std::endl;

  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 64; j++) {
      if (map_mask[i][j] == 'H')
        objects.push_back(new Hero(resource_manager->textures[1]));
      else if (map_mask[i][j] == '=')
        objects.push_back(new Tile(j*30, i*30, resource_manager->textures[2]));
    }
  }

}

void Game::Level::deInitMap() {
  delete [] map_mask;
}

int Game::Level::initObjects(int level_number) {
  createObjectsByMask();
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

  Level level;

  level.resource_manager->loadTextures();

  sf::Sprite backgroundSprite(level.resource_manager->textures[0]);
  backgroundSprite.setScale(1.7, 1.7);

  sf::Clock clock;

  int objects_amount = level.initObjects(1);
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
        level.deInitObjects();
        return;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        level.deInitObjects();
        return;
      }
    } 

    Camera.setCenter(level.objects[0]->getSprite().getPosition());

    for (int i = 0; i < objects_amount; i++) {
        level.objects[i]->update(time);
    }

    //window.setView(Camera);
    window.clear(sf::Color::White);  
    window.draw(backgroundSprite);
    for (int i = 0; i < objects_amount; i++) 
      window.draw(level.objects[i]->getSprite());
    window.display();
  }
}
