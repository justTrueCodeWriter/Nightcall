#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/UsualTile.hpp"
#include "../include/Swordsman.hpp"
#include "../include/Button.hpp"
#include "../include/Door.hpp"
#include "../include/UsualSpikes.hpp"

#include <iostream>
#include <string>
#include <algorithm>

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
                      "=     H                                                       =",
                      "=                                                             =",
                      "=                                                             =",
                      "=                                                             =",
                      "=     =                                                       =",
                      "=      =                                                      =",
                      "=       =                                                     =",
                      "=        =           =                                        =",
                      "=         =  S      bd                                        =",
                      "==========================^===================================="
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
      switch (map_mask[i][j]) {
        case'H':
          hero_index = objects_counter;
          objects.push_back(new Hero(j*64, i*64));
          break;
        case '=':
          objects.push_back(new UsualTile(j*64, i*64));
          objects_counter++;
          break;
        case 'S':
          objects.push_back(new Swordsman(j*64, i*64));
          objects_counter++;
          break;
        case 'b':
          objects.push_back(new Button(j*64, i*64));
          objects_counter++;
          break;
        case 'd':
          objects.push_back(new Door(j*64, i*64));
          objects_counter++;
          break;
        case '^':
          objects.push_back(new UsualSpikes(j*64, i*64));
          objects_counter++;
          break;
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

void Game::Collider::processCollision(std::vector<Object*> objects, int objects_amount, int hero_index) {
  std::string title = "collide ";
    for (int i = 0; i < objects_amount; i++) {
      if (i != hero_index && objects[i]->getSprite().getGlobalBounds().intersects(objects[hero_index]->getSprite().getGlobalBounds())) {
        }
    }
}

void Game::gameLoop(sf::RenderWindow &window) {

  sf::Sprite backgroundSprite(*ResourceManager::getInstance().getTexture('B'));
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
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        deInitObjects();
        return;
      }
    } 

    Camera.setCenter(objects[hero_index]->getSprite().getPosition());

    for (auto &obj : objects) {
      obj->update(time);
    }

    while (!message_buffer.empty()) {
      Message *msg = message_buffer.back();
      message_buffer.pop_back();
      if (msg->action == DIED) {
        auto it = std::find(objects.begin(), objects.end(), msg->died.who);
        objects.erase(it);
      }
      for (auto obj : objects) {
        obj->sendMessage(msg);
      }
      delete msg;
    }

    //collider.processCollision(objects, objects_amount, hero_index);
    
    window.setView(Camera);
    window.clear(sf::Color::Black);  
    //window.draw(backgroundSprite);
    for (int i = 0; i < objects_amount; i++) 
      window.draw(objects[i]->getSprite());
    window.display();
  }
}