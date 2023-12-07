#include "../include/Hero.hpp"

Hero::Hero() {
  x_ = 50;
  y_ = 900;
  texture.loadFromFile("media/img/Fifteen.png");
  sprite.setTexture(texture);
  sprite.setScale(2, 2);
}

void Hero::load(float time) { move(time); }
sf::Sprite Hero::getSprite() { return sprite; }

void Hero::move(float time) {
  
    float speed = 0;
    static float current_frame = 0;
    static bool isConsistent = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = -1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = 1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      side_ = -1;
      speed = walk_speed_/2;
      
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      side_ = 1;
      speed = walk_speed_/2;

      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || isConsistent) {
      speed = dash(time, isConsistent);
    }
    else {
      current_frame += 0.01*time;
      if (current_frame > 12) current_frame = 0;
      if (side_ > 0)
        sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 42));
      else if  (side_ < 0)
        sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36)+36, 244, -36, 42));
    }

    x_ += side_*speed*time;
    sprite.setPosition(x_, y_); 
}

float Hero::dash(float time, bool &isConsistent) {
 static float current_frame = 0;  
 isConsistent = true;

 if (current_frame > 6) {
   current_frame = 0;
   isConsistent = false;
 }
 current_frame += 0.03*time;
 if (side_ > 0)
  sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58), 768, 58, 42));
 else if (side_ < 0)
  sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58)+58, 768, -58, 42));
 return run_speed_*3;
}
