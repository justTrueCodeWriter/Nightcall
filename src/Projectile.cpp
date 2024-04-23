#include "../include/Projectile.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"


Projectile::Projectile(float x, float y){
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('s'));
  sprite.setTextureRect(sf::IntRect(354, 289, 13, 13));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
}

void Projectile::update(float time){

}

void Projectile::sendMessage(Message* message){

}