#include "Game.h"

Game::Game() {
    if (!warriorTexture.loadFromFile("warrior.gif")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    warriorSprite.setTexture(warriorTexture);
    warriorSprite.setPosition(position);
    warriorSprite.setScale(1.f, 1.f);

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

    if (!attackTexture.loadFromFile("sword-warrior.gif")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    attackSprite.setTexture(attackTexture);
    attackSprite.setScale(0.3f, 0.3f);

    if (!statTexture.loadFromFile("statDisplay.png")) {
        std::cout << "No such file in directory!!" << std::endl;
    }
    statSprite.setTexture(statTexture);
    statSprite.setPosition(24.f,12.5f);
    statSprite.setScale(0.5f, 0.5f);
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
        facing = LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += movementSpeed * dt;
        facing = RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y += -movementSpeed * dt;
        facing = UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += movementSpeed * dt;
        facing = DOWN;
    }

    warriorSprite.setPosition(position);
    mageSprite.setPosition(position);
    elfSprite.setPosition(position);
}
void Game::attack(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        float offset = 50.f;
        sf::FloatRect spriteBounds = attackSprite.getGlobalBounds();

        switch (facing) {
        case UP:
            attackPosition = position + sf::Vector2f(-spriteBounds.width / 2.f, -offset - spriteBounds.height / 2.f);
            break;
        case DOWN:
            attackPosition = position + sf::Vector2f(-spriteBounds.width / 2.f, offset);
            break;
        case LEFT:
            attackPosition = position + sf::Vector2f(-offset - spriteBounds.width / 2.f, -spriteBounds.height / 2.f);
            break;
        case RIGHT:
            attackPosition = position + sf::Vector2f(offset, -spriteBounds.height / 2.f);
            break;
        default:
            break;
        }

        attackSprite.setPosition(attackPosition);
        window.draw(attackSprite);
    }
}



void Game::displayStats(int health, int mana, int defense, int energy, sf::RenderWindow& window, CharacterEnum character) {

    window.draw(statSprite);

    //HEALTH
    float HealthWidth = NULL;

    switch (character) {
    case WARRIOR: 
        HealthWidth = 0.05f;
        break;
    case MAGE: 
        HealthWidth = 0.1f;
        break;
    case ELF: 
        HealthWidth = 0.07f;
        break;
    default:
        HealthWidth = 0.05f; 
        break;
    }

    float height = 18.f;
    healthBarVec.clear();

    for (int i = 0; i < health; i++) {
        sf::RectangleShape healthBar(sf::Vector2f(HealthWidth, height));
        healthBar.setFillColor(sf::Color::Red);
        healthBar.setPosition(80 + (i * HealthWidth), 40);
        healthBarVec.push_back(healthBar);
    }

    for (const auto& healthPoint : healthBarVec) {
        window.draw(healthPoint);
    }

    //MANA
    float ManaWidth = NULL;

    switch (character) {
    case WARRIOR:
        ManaWidth = 2.f;
        break;
    case MAGE:
        ManaWidth = 0.66f;
        break;
    case ELF:
        ManaWidth = 0.05f;
        break;
    default:
        ManaWidth = 0.25f;
        break;
    }

    manaBarVec.clear();

    for (int i = 0; i < mana; i++) {
        sf::RectangleShape manaBar(sf::Vector2f(ManaWidth, height));
        manaBar.setFillColor(sf::Color::Blue);
        manaBar.setPosition(80 + (i * ManaWidth), 104);
        manaBarVec.push_back(manaBar);
    }

    for (const auto& manaPoint : manaBarVec) {
        window.draw(manaPoint);
    }

    // Defense 
    float DefenseWidth = NULL; 
    switch (character) {
    case WARRIOR:
        DefenseWidth = 0.2f;
        break;
    case MAGE:
        DefenseWidth = 0.5f;
        break;
    case ELF:
        DefenseWidth = 0.4f;
        break;
    default:
        DefenseWidth = 0.2f;
        break;
    }
    defenseBarVec.clear();
    for (int i = 0; i < defense; i++) {
        sf::RectangleShape defenseBar(sf::Vector2f(DefenseWidth, height));
        defenseBar.setFillColor(sf::Color::Green);
        defenseBar.setPosition(80 + (i * DefenseWidth), 171);
        defenseBarVec.push_back(defenseBar);
    }
    for (const auto& defensePoint : defenseBarVec) {
        window.draw(defensePoint);
    }

    // Energy 
    float EnergyWidth = 0.25f; 
    switch (character) {
    case WARRIOR:
        EnergyWidth = 0.25f;
        break;
    case MAGE:
        EnergyWidth = 0.2f;
        break;
    case ELF:
        EnergyWidth = 0.1f;
        break;
    default:
        EnergyWidth = 0.2f;
        break;
    }
    energyBarVec.clear();
    for (int i = 0; i < energy; i++) {
        sf::RectangleShape energyBar(sf::Vector2f(EnergyWidth, height));
        energyBar.setFillColor(sf::Color::Yellow);
        energyBar.setPosition(80 + (i * EnergyWidth), 239);
        energyBarVec.push_back(energyBar);
    }
    for (const auto& energyPoint : energyBarVec) {
        window.draw(energyPoint);
    }
}
