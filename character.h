#pragma once
#include "CharacterEnum.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Character {
public:
    virtual void stats(int* health, int* attack, int* mana, int* defense, int* energy) = 0;
    virtual CharacterEnum characterClass() = 0;
    virtual ~Character() = default;
    sf::Vector2f position = { 300.f, 300.f };
    
};

class Warrior : public Character {
public:
    void stats(int* health, int* attack, int* mana, int* defense, int* energy) override;
    CharacterEnum characterClass() override;
};

class Mage : public Character {
public:
    void stats(int* health, int* attack, int* mana, int* defense, int* energy) override;
    CharacterEnum characterClass() override;
};

class Elf : public Character {
public:
    void stats(int* health, int* attack, int* mana, int* defense, int* energy) override;
    CharacterEnum characterClass() override;
};
