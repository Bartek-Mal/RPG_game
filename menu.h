#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "StateEnum.h"
#include "LoginEnum.h"
#include <iostream>

class Menu {
public:
    Menu();
    ~Menu();
    virtual void MenuDisplay(sf::RenderWindow& window);
    void mousePosition(sf::RenderWindow& window, sf::RectangleShape& startButton, sf::RectangleShape& exitButton, sf::Event& event);
    sf::Color Brown = sf::Color(139, 69, 19);
    sf::Color darkGreen = sf::Color(0, 100, 0);
    sf::Font font;
    LoginEnum current;

    virtual StateEnum getCurrentWindow() const;
protected:
    StateEnum currentWindow;
    sf::Text start;
    sf::Text exit;
};

#endif // MENU_H
