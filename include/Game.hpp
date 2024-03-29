#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Object.hpp"
#include "UsualTile.hpp"
#include "ResourceManager.hpp"
#include "Message.hpp"
#include <vector>
#include <list>

class Game 
{
  public:
    static Game& getInstance() {
      static Game instance;
      return instance;
    }

    void gameLoop(sf::RenderWindow &window);
    int initObjects();
    void deInitObjects();
    void sendMessage(Message* message);

    class Level {
      public:
        void initMap();
        std::vector<std::string>* getMapMask();
        void deInitMap();
      private: 
        std::vector<std::string> map_mask;
    };

  private:
    Game(){}; 
    Game(const Game&){};

    Level level;
    std::vector <Object*> objects;
    std::vector<UsualTile*> tiles;
    std::list<Message*> message_buffer;
    int hero_index = 0;
};
