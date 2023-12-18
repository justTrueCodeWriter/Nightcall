#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/Tile.hpp"

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
      objects.push_back(new Tile); 
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
  return objects.size();
}

void Game::Level::deInitObjects() {
  objects.clear();
}

void Game::gameCycle(sf::RenderWindow &window) {

  sf::Clock clock;

  Level level;
  int objects_amount = level.initObjects(1);

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
// sizeof(level.objects)/sizeof(level.objects[0])
    for (int i = 0; i < objects_amount; i++) 
      level.objects[i]->update(time);

    window.clear(sf::Color::White);  
    for (int i = 0; i < objects_amount; i++) 
      window.draw(level.objects[i]->getSprite());
    window.display();
  }
}
