#include <SFML/Graphics.hpp>
#include "menu.h"
#include "LoginMenu.h"
#include "StateEnum.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "RougeLike");

    // Background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    LoginMenu login;
    Menu menu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        if (login.getCurrentWindow() == LOGIN) {
            login.textBox(window);
        }
        else if (menu.getCurrentWindow() == MAINMENU) {
            menu.MenuDisplay(window);
        }
        else if (menu.getCurrentWindow() == GAME) {
            // Future implementation for the game
        }
        window.display();
    }

    return 0;
}
