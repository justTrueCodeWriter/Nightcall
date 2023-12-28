#include <SFML/Graphics/Rect.hpp>
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

    class Level {
      public:
        void initMap();
        std::vector<std::string>* getMapMask();
        void deInitMap();
      private: 
        std::vector<std::string> map_mask;
    };

    class Collider {
      public:
        void getHeroMessage(std::string message);
        void processCollision(std::vector <Object*> objects, int objects_amount, int hero_index);
      private:
        std::string message_ = "";
    };

  private:

    Level level;
    Collider collider;
    std::vector <Object*> objects;
    //TODO: system of message {
    //list of message
    //sendMessage to objects
    //}
    //game singleton
    //collide cube on foot of hero

    int width_ = 1920, height_ = 1080;
    int hero_index = 0;

    std::string window_title_ = "Nighcall";
};
