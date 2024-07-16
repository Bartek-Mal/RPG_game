#include "menu.h"

void Menu::MenuDisplay(sf::RenderWindow& window) {
    sf::RectangleShape button(sf::Vector2f(buttonSizeX, buttonSizeY));
    button.setFillColor(sf::Color::Cyan);
    button.setPosition(300.f, 250.f);

    window.draw(button); 
}
