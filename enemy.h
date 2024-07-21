#pragma once
#include "Game.h"
#include "SFML/Graphics.hpp"
class Enemy
{
public:
	Enemy();
	~Enemy();
	void stats(int* health, int* attack, int* mana, int* defense, int* energy);
	void enemy(sf::RenderWindow& window);
	void tracking(sf::Vector2f playerPos);
	sf::Vector2f trackingField;
	sf::Clock clock;

	sf::Vector2f getPosition();
protected:
	sf::Texture trollTexture;
	sf::Sprite trollSprite;
	sf::Vector2f position = { 500.f, 100.f };
};

