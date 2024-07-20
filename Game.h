#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterEnum.h"
#include "FacingEnum.h"
#include <iostream>
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void getStats(int* health, int* attack, int* mana, int* defense, int* energy);
    void movement();
    void player(CharacterEnum character, sf::RenderWindow& window);
    void displayStats(int health, int mana, int defense, int energy, sf::RenderWindow& window, CharacterEnum character);
    FacingEnum facing;
    void attack(sf::RenderWindow& window);
    sf::Vector2f getPosition();

private:
    sf::Vector2f position = { 300.f, 300.f };

    //tekstury do animacji
    std::vector<sf::Texture> warriorTextures;

    //tekstury postaci
    sf::Sprite warriorSprite;
    sf::Texture mageTexture;
    sf::Sprite mageSprite;
    sf::Texture elfTexture;
    sf::Sprite elfSprite;
    sf::Sprite statSprite;
    sf::Texture statTexture;
    sf::Sprite attackSprite;
    sf::Texture attackTexture;

    //zegar
    sf::Clock clock;

    //pozycja atak
    sf::Vector2f attackPosition;

    //kamera
    sf::View view;

    //health bars
    std::vector<sf::RectangleShape> healthBarVec;
    std::vector<sf::RectangleShape> manaBarVec;
    std::vector<sf::RectangleShape> defenseBarVec;
    std::vector<sf::RectangleShape> energyBarVec;
    
    //animation 
    sf::Clock animationClock;
    unsigned int currentFrame = 0; 
};
