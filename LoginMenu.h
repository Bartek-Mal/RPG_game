#pragma once

#include <SFML/Graphics.hpp>
#include "menu.h"
#include "StateEnum.h"
#include "LoginEnum.h"
#include <iostream>
#include <regex>

class LoginMenu : public Menu
{
public:
    LoginMenu();
    ~LoginMenu();
    void textBox(sf::RenderWindow& window);
    StateEnum getCurrentWindow() const override;
    std::regex loginValidation;
private:
    sf::Text nickname;
    sf::Text password;
    std::string inputText;
    std::string nicknameInput;
    std::string passwordInput;
};
