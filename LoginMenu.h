#pragma once

#include <SFML/Graphics.hpp>
#include "MenuEnum.h"
#include "LoginEnum.h"
#include <regex>

class LoginMenu
{
public:
	void Login();
	void textBox(sf::RenderWindow& window);
	sf::Color Brown = sf::Color(139, 69, 19);
	sf::Color darkGreen = sf::Color(0, 100, 0);
	MenuEnum getCurrentWindow() const;
private:
	MenuEnum currentWindow = LOGIN;
	sf::Font font;
	sf::Text nickname;
	sf::Text password;
	std::string inputText;
	LoginEnum current;
	std::string nicknameInput;
	std::string passwordInput;
};

