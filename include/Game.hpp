#include <string>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
class Game
{
private:
    int width_ = 1920, height_ = 1080;
    std::string window_title = "Nighcall";
public:
    int getWidth() {
        return width_;
    }
    int getHeight() {
        return height_;
    }
    std::string getWindowTitle() {
        return window_title;
    }
    void gameCycle(sf::RenderWindow &window);
};
