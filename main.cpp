#include <SFML/Graphics.hpp>
#include "menu.h"
#include "LoginMenu.h"
#include "StateEnum.h"
#include "characterClass.h"
#include "character.h"
#include "Game.h"
#include "enemy.h"
#include <iostream>
#include <memory>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "RogueLike");

    // Background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    LoginMenu login;
    Menu menu;
    CharacterClass characterClass;
    Game game;
    Enemy enemy;
    std::unique_ptr<Character> playerCharacter = nullptr;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        if (login.getCurrentWindow() == LOGIN) {
            login.textBox(window);
        }
        else if (menu.getCurrentWindow() == MAINMENU) {
            menu.MenuDisplay(window);
        }
        else if (menu.getCurrentWindow() == CHARACTER) {
            characterClass.characterClassChoice(window);
            if (characterClass.getCharacterClass() == WARRIOR) {
                playerCharacter = std::make_unique<Warrior>();
            }
            else if (characterClass.getCharacterClass() == MAGE) {
                playerCharacter = std::make_unique<Mage>();
            }
            else if (characterClass.getCharacterClass() == ELF) {
                playerCharacter = std::make_unique<Elf>();
            }
            if (characterClass.getCurrentWindow() == GAME) {
                if (playerCharacter) {
                    window.clear();
                    int health, attack, mana, defense, energy;
                    playerCharacter->stats(&health, &attack, &mana, &defense, &energy);
                    game.movement();  
                    game.displayStats(health,mana,defense,energy,window, playerCharacter->characterClass());
                    game.attack(window);
                    game.player(playerCharacter->characterClass(), window);
                    enemy.enemy(window);
                    enemy.tracking(game.getPosition());
                    std::cout << "GAME" << std::endl;
                }
            }
        }

        window.display();
    }

    return 0;
}