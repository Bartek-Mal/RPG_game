#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    void MenuDisplay(sf::RenderWindow& window);
private:
    int buttonSizeX = 200.f;
    int buttonSizeY = 50.f;
};

#endif // MENU_H
