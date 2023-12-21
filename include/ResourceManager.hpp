#include <SFML/Graphics.hpp>

class ResourceManager {
  public:
    ResourceManager(char *possibleObjectTypes);

    std::vector<sf::Texture> textures;
    char possibleObjectTypes_[3] = {'B', 'H', '='};

    void loadTextures();
    sf::Texture *getTexture(char message);

};
