#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "../include/Object.hpp"
#include <vector>

class Game
{
  public:
    int getWidth() { return width_; }
    int getHeight() { return height_; }
    std::string getWindowTitle() { return window_title_; }

    void gameCycle(sf::RenderWindow &window);

    class Level {
      public:
        std::vector <Object*> objects;
        
        void initMap(int level_number);
        int initObjects(int level_number);
        void deInitMap();
        void deInitObjects();
        void checkCollision(Object* objects1, Object* objects2);
      private: 
        char **map_mask;
        std::vector<char> possible_objects = {'#'};
        void createMapByMask();
        void createObjectVector();
    };

  private:

    int width_ = 1920, height_ = 1080;

    std::string window_title_ = "Nighcall";
};
