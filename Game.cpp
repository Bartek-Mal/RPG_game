#include "Game.h"

Game::Game() {
    if (!warriorTexture.loadFromFile("character1.gif")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    warriorSprite.setTexture(warriorTexture);
    warriorSprite.setPosition(position);
    warriorSprite.setScale(0.5f, 0.5f);

    if (!mageTexture.loadFromFile("mage.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    mageSprite.setTexture(mageTexture);
    mageSprite.setPosition(position);
    mageSprite.setScale(0.3f, 0.3f);

    if (!elfTexture.loadFromFile("character.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    elfSprite.setTexture(elfTexture);
    elfSprite.setPosition(position);
    elfSprite.setScale(0.3f, 0.3f);
}

Game::~Game() {}

void Game::player(CharacterEnum character, sf::RenderWindow& window) {
    switch (character) {
    case WARRIOR:
        window.draw(warriorSprite);
        break;
    case MAGE:
        window.draw(mageSprite);
        break;
    case ELF:
        window.draw(elfSprite);
        break;
    default:
        break;
    }
}

void Game::getStats(int* health, int* attack, int* mana, int* defense, int* energy) {
    
}

void Game::movement() {
    float movementSpeed = 200.0f;
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position.x += -movementSpeed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += movementSpeed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y += -movementSpeed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += movementSpeed * dt;
    }

    warriorSprite.setPosition(position);
    mageSprite.setPosition(position);
    elfSprite.setPosition(position);
}

void Game::displayStats() {
    
}