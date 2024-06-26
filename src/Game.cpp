#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/Swordsman.hpp"
#include "../include/Shooter.hpp"
#include "../include/Button.hpp"
#include "../include/Door.hpp"
#include "../include/UsualSpikes.hpp"
#include "../include/Laser.hpp"
#include "../include/Trampoline.hpp"
#include "../include/AutomaticSpikes.hpp"
#include "../include/TriggerGates.hpp"
#include "../include/SavePoint.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>



void Game::Level::initMap() {
  std::vector<std::string> map;
  std::ifstream fin;
  std::string line;

  fin.open("media/maps/map.txt");

  while (std::getline(fin, line))
    map_mask.push_back(line);

  fin.close();

}

std::vector<std::string>* Game::Level::getMapMask() { return &map_mask; }

void Game::Level::deInitMap() {
  map_mask.clear();
}

void Game::initObjects() {
  srand((unsigned)time(0));
  static int objects_counter = 0;
  level.initMap();  
  std::vector<std::string> map_mask = *level.getMapMask(); 
  int map_height = map_mask.size();
  int map_width = map_mask[0].size();

  for (int i = 0; i < map_height; i++) {
    for (int j = 0; j < map_width; j++) {
      switch (map_mask[i][j]) {
        case 'H':
          hero_index = objects_counter;
          objects.push_back(new Hero(j*64, i*64));
          save_point.x = j*64, save_point.y = i*64;
          break;
        case '=':
          tiles.push_back(new UsualTile(j*64, i*64));
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
        case 's':
          objects.push_back(new Shooter(j*64, i*64));
          objects_counter++;
          break;
        case '|':
          objects.push_back(new Laser(j*64, i*64));
          objects_counter++;
          break;
        case '~':
          objects.push_back(new Trampoline(j*64, i*64));
          objects_counter++;
          break;
        case 'T':
          objects.push_back(new TriggerGates(j*64, i*64));
          objects_counter++;
          break;
        case '?':
          objects.push_back(new AutomaticSpikes(j*64, i*64));
          objects_counter++;
          tiles.push_back(new UsualTile(j*64, i*64));
          break;
        case '@':
          objects.push_back(new SavePoint(j*64, i*64));
          objects_counter++;
          break;

      }
    }
  }

}

void Game::deInitObjects() {
  objects.clear();
  tiles.clear();
}

void Game::pushObject(Object* object) {
  objects.push_back(object);
}

void Game::sendMessage(Message *message) { message_buffer.push_back(message); }

//return weight of collision with ground
int Game::processCollision(Object &object, UsualTile &tile) {
  sf::FloatRect collide_rect;

  if (!object.isColliding())
    return -1;

  if (object.getSprite().getGlobalBounds().intersects(tile.getSprite().getGlobalBounds(), collide_rect)) {
    if (collide_rect.width > collide_rect.height) {
      if (object.getSprite().getGlobalBounds().top > tile.getSprite().getGlobalBounds().top) {
        object.shift(0, -(collide_rect.height)); 
      }
      else if (object.getSprite().getLocalBounds().top < tile.getSprite().getGlobalBounds().top) {
        object.shift(0, collide_rect.height);
        return 1;
      }
    }
    else if (collide_rect.width < collide_rect.height) {
      if(object.getSprite().getGlobalBounds().left < tile.getSprite().getGlobalBounds().left)
        object.shift(-collide_rect.width, 0);
      else if (object.getSprite().getGlobalBounds().left > tile.getSprite().getGlobalBounds().left)
        object.shift(collide_rect.width, 0);
    }
  }
  return 0;
}

void Game::checkSaveMessage(Message* message) {
  if (dynamic_cast<SavePoint*>(message->sender) != nullptr && message->action == SAVE) {
    save_point.x = message->sender->getSprite().getPosition().x;
    save_point.y = message->sender->getSprite().getPosition().y; 
  }
}

void Game::gameLoop(sf::RenderWindow &window) {

  sf::Sprite backgroundSprite(*ResourceManager::getInstance().getTexture('B'));
  backgroundSprite.setScale(1.7, 1.7);

  sf::Clock clock;
  
  initObjects();

  sf::View Camera(sf::FloatRect(0, 0, 600, 300));

  while (window.isOpen()) {
    float time = clock.getElapsedTime().asMilliseconds();
    clock.restart();
    sf::Event event;
    while (window.pollEvent(event)) {
      static bool isQKeyPressed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        deInitObjects();
        return;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        if (!isQKeyPressed) {
          Camera.zoom(-4);
          Camera.rotate(180);
          isQKeyPressed = true;
        }
      } else {
        isQKeyPressed = false;
        Camera.reset(sf::FloatRect(0, 0, 600, 300));
      }
    }

    Camera.setCenter(objects[hero_index]->getSprite().getPosition());


    for (auto &obj : objects) {
      obj->update(time);
    }

    while (!message_buffer.empty()) {
      Message *message = message_buffer.back();
      message_buffer.pop_back();
      checkSaveMessage(message);
      if (message->action == DIED) {
        if (dynamic_cast<Hero *>(message->died.who) != nullptr) {
          objects[hero_index]->setPosition(save_point.x, save_point.y);
          message_buffer.clear();
          delete message;
          break;
        }
        auto it = std::find(objects.begin(), objects.end(), message->died.who);
        objects.erase(it);
        hero_index = 0;
        for (auto obj : objects) {
          if (dynamic_cast<Hero *>(obj))
            break;
          hero_index++;
        }
      }
      for (auto obj : objects) {
        obj->sendMessage(message);
      }
      delete message;
    }


    //------Collision processing
    for (auto &obj : objects) {
      int collision_weights_sum = 0;
      for (auto &tile : tiles) {
        int collision_weight = processCollision(*obj, *tile);
        if (collision_weight == -1)
          break;
        collision_weights_sum += collision_weight;
      }
      collision_weights_sum == 0 ? obj->isGround = false : obj->isGround = true;
    }

    window.setView(Camera);
    window.clear(sf::Color(245, 239, 230, 255));
    for (auto object : objects)
      window.draw(object->getSprite());
    for (auto tile : tiles)
      window.draw(tile->getSprite());
    window.display();
  }
}