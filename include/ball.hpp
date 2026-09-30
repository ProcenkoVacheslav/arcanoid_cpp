#pragma once
#include "Constants.hpp"
#include "blocks.hpp"
#include "carete.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Ball {
private:
    float posX;
    float posY;
    int radius;
    sf::Color color;
    
    const float SPEED = Constants::ballSpeed;

    float verticalSpeed;
    float horysontalSpeed;

    sf::CircleShape ballObject;

    void checkWals();
    void setSpeed(int angle);

public:
    Ball(float startPosX, float startPosY, int ballRadius, sf::Color ballColor, int startAngel);
    ~Ball() = default;

    void Move();
    void Blit(sf::RenderWindow & window);
    void Colide(Carete & carete);
    int ColideBlock(IBlock & block);

    float getPosX();
    float getPosY();
    int getRadius();
};

