#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Object.hpp"
#include "ResourceManager.hpp"
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
        ResourceManager *resource_manager;
        
        void initMap(int level_number);
        int initObjects(int level_number);
        void deInitMap();
        void deInitObjects();
        void checkCollision(Object* objects1, Object* objects2);
      private: 
        std::string *map_mask;
        void createObjectsByMask();
    };

  private:

    int width_ = 1920, height_ = 1080;

    std::string window_title_ = "Nighcall";
};
