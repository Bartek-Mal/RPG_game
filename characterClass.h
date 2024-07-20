#pragma once
#include <SFML/Graphics.hpp>
#include "StateEnum.h"
#include "menu.h"
#include "CharacterEnum.h"
#include <iostream>

class CharacterClass : public Menu
{
public:
    CharacterClass();
    ~CharacterClass();
    void characterClassChoice(sf::RenderWindow& window);
    StateEnum getCurrentWindow() const override;
    void mousePosition(sf::RenderWindow& window, sf::Sprite warrior, sf::Sprite mage, sf::Sprite elf, sf::Event& event);
    CharacterEnum getCharacterClass() const;
    CharacterEnum characterClass;

private:
    sf::Texture warrior;
    sf::Sprite warriorSprite;
    sf::Texture mage;
    sf::Sprite mageSprite;
    sf::Texture elf;
    sf::Sprite elfSprite;
    sf::Texture characterDisplayTexture;
    sf::Sprite characterDisplaySprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};
