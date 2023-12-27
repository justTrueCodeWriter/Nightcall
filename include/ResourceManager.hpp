#include <SFML/Graphics.hpp>

class ResourceManager {
  private:
    std::vector<sf::Texture> textures;
    char possibleObjectTypes_[4] = {'B', 'H', '=', 'S'};
    ResourceManager();
    ResourceManager(const ResourceManager&);
  public:
    static ResourceManager& getInstance() {
      static ResourceManager instance;
      return instance;
    }

    sf::Texture* getTexture(char message);

};
