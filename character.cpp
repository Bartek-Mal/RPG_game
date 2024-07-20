#include "character.h"

//warrior
void Warrior::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 2000;
    *attack = 500;
    *mana = 50;
    *defense = 500;
    *energy = 400;
}

CharacterEnum Warrior::characterClass() {
    return WARRIOR;
}

//mage
void Mage::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 1000;
    *attack = 1000;
    *mana = 1500;
    *defense = 200;
    *energy = 500;
}

CharacterEnum Mage::characterClass() {
    return MAGE;
}

//elf
void Elf::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 1500;
    *attack = 800;
    *mana = 400;
    *defense = 250;
    *energy = 1000;
}

CharacterEnum Elf::characterClass() {
    return ELF;
}
