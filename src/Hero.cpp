#include "../include/Hero.hpp"

Hero::Hero() {
  texture.loadFromFile("media/img/Fifteen.png");
  sprite.setTexture(texture);
  sprite.setPosition(50, 900);
  sprite.setScale(2, 2);
}

void Hero::move(float time) {
  
    static int side = 1;
    static float current_frame = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      sprite.move(-run_speed_*time, 0); 
      current_frame += 0.01*time;
      if (current_frame > 10) current_frame -= 10;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      sprite.move(run_speed_*time, 0); 
      current_frame += 0.01*time;
      if (current_frame > 10) current_frame -= 10;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      sprite.move(-walk_speed_*time/2, 0); 
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 43));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      sprite.move(walk_speed_*time/2, 0); 
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 43));
    }
    else {
      current_frame += 0.01*time;
      if (current_frame > 12) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 42));
    }
}
