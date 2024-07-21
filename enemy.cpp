#include "enemy.h"

Enemy::Enemy() {
    if (!trollTexture.loadFromFile("troll.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    trollSprite.setTexture(trollTexture);
    trollSprite.setPosition(position);
    trollSprite.setScale(0.2f, 0.2f);
}

Enemy::~Enemy() {};

void Enemy::enemy(sf::RenderWindow& window) {
    window.draw(trollSprite);
}

void Enemy::tracking(sf::Vector2f playerPos) {
    float movementSpeed = 80.0f;
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();

    if (position.x > playerPos.x && position.y < playerPos.y) {
        position.x += -movementSpeed * dt;
        position.y += movementSpeed * dt;
    }
    else if (position.x < playerPos.x && position.y > playerPos.y) {
        position.x += movementSpeed * dt;
        position.y += -movementSpeed * dt;
    }
    else if (position.x < playerPos.x && position.y < playerPos.y) {
        position.x += movementSpeed * dt;
        position.y += movementSpeed * dt;
    }
    else if (position.x > playerPos.x && position.y > playerPos.y) {
        position.x += -movementSpeed * dt;
        position.y += -movementSpeed * dt;
    }


    trollSprite.setPosition(position);
}

sf::Vector2f Enemy::getPosition() {
    return position;
}
