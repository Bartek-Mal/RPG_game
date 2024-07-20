#include "characterClass.h"

CharacterClass::CharacterClass() {
    currentWindow = CHARACTER;
    //warrior
    if (!warrior.loadFromFile("warrior.gif")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    else {
        warriorSprite.setTexture(warrior);
        warriorSprite.setPosition(70, 70);
        warriorSprite.setScale(2.f, 2.f);
    }
    //mage
    if (!mage.loadFromFile("mage.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    else {
        mageSprite.setTexture(mage);
        mageSprite.setPosition(350, 100);
        mageSprite.setScale(0.4f, 0.4f);
    }
    //elf
    if (!elf.loadFromFile("character.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    else {
        elfSprite.setTexture(elf);
        elfSprite.setPosition(500,100);
        elfSprite.setScale(0.5f, 0.5f);
    }

    if (!backgroundTexture.loadFromFile("dungeon.jpg")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    else {
        backgroundSprite.setTexture(backgroundTexture);
    }
    if (!characterDisplayTexture.loadFromFile("characterDisplay.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    else {
        characterDisplaySprite.setTexture(characterDisplayTexture);
        characterDisplaySprite.setPosition(100, 100);
        characterDisplaySprite.setScale(1.f, 1.f);
    }
}
CharacterClass::~CharacterClass() {};
void CharacterClass::characterClassChoice(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        mousePosition(window, warriorSprite, mageSprite, elfSprite, event);
    }

    window.draw(backgroundSprite);
    window.draw(characterDisplaySprite);
    window.draw(warriorSprite);
    window.draw(mageSprite);
    window.draw(elfSprite);
}

StateEnum CharacterClass::getCurrentWindow() const {
    return currentWindow;
}

void CharacterClass::mousePosition(sf::RenderWindow& window, sf::Sprite warrior, sf::Sprite mage, sf::Sprite elf, sf::Event& event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (warrior.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            characterClass = WARRIOR;
            currentWindow = GAME;
        }
        else if (mage.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            characterClass = MAGE;
            currentWindow = GAME;
        }
        else if (elf.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            characterClass = ELF;
            currentWindow = GAME;
        }
    }
}


CharacterEnum CharacterClass::getCharacterClass() const {
    return characterClass;
}


