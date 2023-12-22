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
    int initObjects();
    void deInitObjects();
    void checkCollision(Object* objects1, Object* objects2);

    class Level {
      public:
        void initMap();
        std::vector<std::string>* getMapMask();
        void deInitMap();
      private: 
        std::vector<std::string> map_mask;
    };

  private:

    Level level;
    ResourceManager *resource_manager;
    std::vector <Object*> objects;

    int width_ = 1920, height_ = 1080;

    std::string window_title_ = "Nighcall";
};
