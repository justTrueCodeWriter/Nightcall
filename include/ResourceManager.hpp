#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>

class ResourceManager {
  public:
    static ResourceManager& getInstance() {
      static ResourceManager instance;
      return instance;
    }

    sf::Texture* getTexture(char message);

  private:
    std::vector<sf::Texture> textures;
    char possibleObjectTypes_[6] = {'B', 'H', '=', 'S', 'b', 'd'};
    ResourceManager();
    ResourceManager(const ResourceManager&);
};
#endif
