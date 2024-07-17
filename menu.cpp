#include "menu.h"

void Menu::MenuDisplay(sf::RenderWindow& window) {
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Vector2f buttonSize(400.f, 50.f);
    sf::Vector2f startButtonPos(200, 300);
    sf::Vector2f exitButtonPos(200, 400);

    // start game
    sf::RectangleShape StartButton(buttonSize);
    StartButton.setPosition(startButtonPos);
    StartButton.setFillColor(Brown);
    StartButton.setOutlineThickness(2);
    StartButton.setOutlineColor(darkGreen);

    // exit
    sf::RectangleShape ExitButton(buttonSize);
    ExitButton.setPosition(exitButtonPos);
    ExitButton.setFillColor(Brown);
    ExitButton.setOutlineThickness(2);
    ExitButton.setOutlineColor(darkGreen);

    if (!font.loadFromFile("silkscreen.ttf")) {
        std::cout << "There is no such font in directory!!" << std::endl;
    }

    //text
    start.setFont(font);
    start.setString("START GAME");
    start.setCharacterSize(24);
    start.setFillColor(sf::Color::Black);

    sf::FloatRect startTextBounds = start.getLocalBounds();
    start.setPosition(
        startButtonPos.x + (buttonSize.x - startTextBounds.width) / 2,
        startButtonPos.y + (buttonSize.y - startTextBounds.height) / 2 - startTextBounds.top
    );

    exit.setFont(font);
    exit.setString("EXIT");
    exit.setCharacterSize(24);
    exit.setFillColor(sf::Color::Black);

    sf::FloatRect exitTextBounds = exit.getLocalBounds();
    exit.setPosition(
        exitButtonPos.x + (buttonSize.x - exitTextBounds.width) / 2,
        exitButtonPos.y + (buttonSize.y - exitTextBounds.height) / 2 - exitTextBounds.top
    );

    while (window.isOpen() && currentWindow == MAINMENU) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            mousePosition(window, StartButton, ExitButton, event);
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(StartButton);
        window.draw(start);
        window.draw(ExitButton);
        window.draw(exit);
        window.display();
    }
}

void Menu::mousePosition(sf::RenderWindow& window, sf::RectangleShape& startButton, sf::RectangleShape& exitButton, sf::Event& event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            currentWindow = GAME;
        }
        else if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            window.close();
        }
    }
}

StateEnum Menu::getCurrentWindow() const {
    return currentWindow;
}
