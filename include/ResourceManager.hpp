#include <SFML/Graphics.hpp>

class ResourceManager {
  private:
    std::vector<sf::Texture> textures;
    char possibleObjectTypes_[3] = {'B', 'H', '='};
    ResourceManager();
    ResourceManager(const ResourceManager&);
  public:
    static ResourceManager& getInstance() {
      static ResourceManager instance;
      return instance;
    }

    //void loadTextures();
    sf::Texture* getTexture(char message);

};
