#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterEnum.h"
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    void getStats(int* health, int* attack, int* mana, int* defense, int* energy);
    void movement();
    void player(CharacterEnum character, sf::RenderWindow& window);
    void displayStats();

private:
    sf::Vector2f position = { 300.f, 300.f };
    sf::Texture warriorTexture;
    sf::Sprite warriorSprite;
    sf::Texture mageTexture;
    sf::Sprite mageSprite;
    sf::Texture elfTexture;
    sf::Sprite elfSprite;
    sf::Clock clock;  
};
