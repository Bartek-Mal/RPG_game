#include "LoginMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

LoginMenu::LoginMenu() : loginValidation("^[A-Za-z0-9]{1,10}$") {
    currentWindow = LOGIN;
}

LoginMenu::~LoginMenu() {};

void LoginMenu::textBox(sf::RenderWindow& window) {

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // User input box
    sf::RectangleShape NicktextBox(sf::Vector2f(400.f, 50.f));
    NicktextBox.setPosition(200, 300);
    NicktextBox.setFillColor(Brown);
    NicktextBox.setOutlineThickness(2);
    NicktextBox.setOutlineColor(darkGreen);

    // Password input box
    sf::RectangleShape PasstextBox(sf::Vector2f(400.f, 50.f));
    PasstextBox.setPosition(200, 400);
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
    nickname.setPosition(220, 310);

    password.setFont(font);
    password.setString("");
    password.setCharacterSize(24);
    password.setFillColor(sf::Color::Black);
    password.setPosition(220, 410);

    while (window.isOpen() && currentWindow == LOGIN) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (current == NICKNAME) {
                    if (event.text.unicode == '\b' && !nicknameInput.empty()) {
                        nicknameInput.pop_back();
                    }
                    else if (event.text.unicode < 128) {
                        if (nicknameInput.length() < 20) {
                            nicknameInput += static_cast<char>(event.text.unicode);
                        }

                    }
                }
                else if (current == PASSWORD) {
                    if (event.text.unicode == '\b' && !passwordInput.empty()) {
                        passwordInput.pop_back();
                    }
                    else if (event.text.unicode < 128) {
                        if (nicknameInput.length() < 20) {
                            passwordInput += static_cast<char>(event.text.unicode);
                        }

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
                if (event.key.code == sf::Keyboard::Enter && std::regex_match(nicknameInput, loginValidation) && std::regex_match(passwordInput, loginValidation)) {
                    currentWindow = MAINMENU;
                }
            }
        }

        if (std::regex_match(nicknameInput, loginValidation)) {
            nickname.setFillColor(sf::Color::Black);
        }
        else {
            nickname.setFillColor(sf::Color::Red);
        }

        if (std::regex_match(passwordInput, loginValidation)) {
            password.setFillColor(sf::Color::Black);
        }
        else {
            password.setFillColor(sf::Color::Red);
        }

        nickname.setString(nicknameInput);
        password.setString(passwordInput);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(NicktextBox);
        window.draw(PasstextBox);
        window.draw(nickname);
        window.draw(password);
        window.display();
    }
}

StateEnum LoginMenu::getCurrentWindow() const {
    return currentWindow;
}
