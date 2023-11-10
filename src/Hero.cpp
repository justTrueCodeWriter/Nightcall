#include "../include/Hero.hpp"

Hero::Hero() {
  x_ = 50;
  y_ = 900;
  texture.loadFromFile("media/img/Fifteen.png");
  sprite.setTexture(texture);
  sprite.setScale(2, 2);
}

void Hero::move(float time) {
  
    int side = 0;
    float speed = 0;
    static float current_frame = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side = -1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side = 1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      side = -1;
      speed = walk_speed_/2;
      
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      side = 1;
      speed = walk_speed_/2;

      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 43));
    }
    else {
      side = 0;

      current_frame += 0.01*time;
      if (current_frame > 12) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 42));
    }

    x_ += side*speed*time;
    sprite.setPosition(x_, y_); 
}
