#include "Game.hpp"

class Menu {
  public:
    int getWidth() { return width_; }
    int getHeight() { return height_; }
    std::string getWindowTitle() { return window_title_; }

    void menuLoop();
  private:
    int width_ = 1920, height_ = 1080;
    std::string window_title_ = "Nighcall";
};
