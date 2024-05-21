#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
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
    void initObjects();
    void deInitObjects();
    void sendMessage(Message* message);
    void pushObject(Object* object);

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
    std::vector <Object*> objects;
    std::vector<UsualTile*> tiles;
    std::list<Message*> message_buffer;
    int hero_index = 0;

    sf::Vector2f save_point = sf::Vector2f(0.0, 0.0);

    Game(){}; 
    Game(const Game&){};

    void processCollision(Object &object, UsualTile &tile);
    void checkSaveMessage(Message* message);
};
