#include "character.h"

//warrior
void Warrior::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 150;
    *attack = 75;
    *mana = 50;
    *defense = 100;
    *energy = 80;
}

CharacterEnum Warrior::characterClass() {
    return WARRIOR;
}

//mage
void Mage::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 100;
    *attack = 150;
    *mana = 300;
    *defense = 50;
    *energy = 50;
}

CharacterEnum Mage::characterClass() {
    return MAGE;
}

//elf
void Elf::stats(int* health, int* attack, int* mana, int* defense, int* energy) {
    *health = 150;
    *attack = 75;
    *mana = 50;
    *defense = 100;
    *energy = 80;
}

CharacterEnum Elf::characterClass() {
    return ELF;
}
