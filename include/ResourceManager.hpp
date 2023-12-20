#include <SFML/Graphics.hpp>

class ResourceManager {
  public:

    std::vector<sf::Texture> textures;
    char possibleTypes[3] = {'H', '#', 'B'};

    void loadTextures();
    sf::Texture getTexture(char message);

};
