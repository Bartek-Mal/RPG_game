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
    void textBox(sf::RenderWindow& window);
    StateEnum getCurrentWindow() const override;
    std::regex loginValidation;
private:
    StateEnum currentWindow = LOGIN;
    sf::Text nickname;
    sf::Text password;
    std::string inputText;
    std::string nicknameInput;
    std::string passwordInput;
};
