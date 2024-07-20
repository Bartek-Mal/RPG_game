#pragma once
#include "Game.h"
#include "SFML/Graphics.hpp"
class enemy
{
	void stats(int* health, int* attack, int* mana, int* defense, int* energy);
	void tracking(sf::Vector2f playerPos);
};

