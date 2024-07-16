#include "LoginMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void LoginMenu::Login() {
}

void LoginMenu::textBox(sf::RenderWindow& window) {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // User input box
    sf::RectangleShape NicktextBox(sf::Vector2f(300.f, 50.f));
    NicktextBox.setPosition(250, 300);
    NicktextBox.setFillColor(Brown);
    NicktextBox.setOutlineThickness(2);
    NicktextBox.setOutlineColor(darkGreen);

    // Password input box
    sf::RectangleShape PasstextBox(sf::Vector2f(300.f, 50.f));
    PasstextBox.setPosition(250, 400);
    PasstextBox.setFillColor(Brown);
    PasstextBox.setOutlineThickness(2);
    PasstextBox.setOutlineColor(darkGreen);

    if (!font.loadFromFile("silkscreen.ttf")) {
        std::cout << "There is no such font in directory!!" << std::endl;
    }

    // Text preparation
    nickname.setFont(font);
    nickname.setString("");
    nickname.setCharacterSize(24);
    nickname.setFillColor(sf::Color::Black);
    nickname.setPosition(260, 310);

    password.setFont(font);
    password.setString("");
    password.setCharacterSize(24);
    password.setFillColor(sf::Color::Black);
    password.setPosition(260, 410);

    while (window.isOpen() && currentWindow == LOGIN) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (current == 1) {
                    if (event.text.unicode == '\b' && !nicknameInput.empty()) {
                        nicknameInput.pop_back();
                    }
                    else if (event.text.unicode < 128) {
                        nicknameInput += static_cast<char>(event.text.unicode);
                    }
                }
                else if (current == 2) {
                    if (event.text.unicode == '\b' && !passwordInput.empty()) {
                        passwordInput.pop_back();
                    }
                    else if (event.text.unicode < 128) {
                        passwordInput += static_cast<char>(event.text.unicode);
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (NicktextBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    current = NICKNAME;
                }
                else if (PasstextBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    current = PASSWORD;
                }
                else {
                    current = NOTHING;
                }
            }
            else if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter){
                    currentWindow = MAINMENU;
                }
            }
        }

        nickname.setString(nicknameInput);
        password.setString(passwordInput);

        window.draw(backgroundSprite);
        window.draw(NicktextBox);
        window.draw(PasstextBox);
        window.draw(nickname);
        window.draw(password);
        window.display();
    }
}

MenuEnum LoginMenu::getCurrentWindow() const {
    return currentWindow;
}