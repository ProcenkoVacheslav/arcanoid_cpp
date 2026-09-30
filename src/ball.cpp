#include "../include/ball.hpp"
#include "../include/MathFunctions.hpp"
#include "../include/Constants.hpp"
#include "../include/carete.hpp"

#include <SFML/System/Vector2.hpp>
#include <cmath>

Ball::Ball(float startPosX, float startPosY, int ballRadius, sf::Color ballColor, int startAngel)
    : ballObject(static_cast<float>(ballRadius)) {
    this->posX = startPosX;
    this->posY = startPosY;
    this->radius = ballRadius;
    this->color = ballColor;

    this->setSpeed(startAngel);

    this->ballObject.setFillColor(this->color);
    this->ballObject.setPosition(sf::Vector2f{this->posX, this->posY});
}

void Ball::setSpeed(int angle) {

    float radians = degreeToRadians(angle);

    this->horysontalSpeed = this->SPEED * std::cos(radians);
    this->verticalSpeed = -this->SPEED * std::sin(radians  );
}

void Ball::checkWals() {
    if (this->posX <= 0 || this->posX >= Constants::windowWidth - 2 * this->radius) {
        this->horysontalSpeed = -this->horysontalSpeed;
    }
    if (this->posY <= 0) {
        this->verticalSpeed = -this->verticalSpeed;
    }
    if (this->posY >= Constants::windowHeight) {
        this->verticalSpeed = 0;
        this->horysontalSpeed = 0;
    }
}

void Ball::Colide(Carete & carete) {
    if (this->verticalSpeed > 0 && (this->posY + 2 * this->radius >= carete.getPosY())) {
        int careteLeftX = carete.getPosX();
        int careteRightX = careteLeftX + carete.getWidth();

        int ballCenterX = this->posX + this->radius;

        if (ballCenterX > careteLeftX && ballCenterX < careteRightX) {
            float hitFactor = static_cast<float>(ballCenterX - careteLeftX) / carete.getWidth();
            int targetAngle = Constants::ballMaxAngle - hitFactor * (Constants::ballMaxAngle - Constants::ballMinAngle);

            this->setSpeed(targetAngle);
        }
    } 
}

void Ball::Move() {
    this->ballObject.setPosition(sf::Vector2f(static_cast<float>(this->posX), static_cast<float>(this->posY)));
    this->checkWals();

    this->posX += this->horysontalSpeed;
    this->posY += this->verticalSpeed;
}

void Ball::Blit(sf::RenderWindow & Window) {
    Window.draw(this->ballObject);
}

float Ball::getPosX() {
    return this->posX;
}

float Ball::getPosY() {
    return this->posY;
}
 
int Ball::getRadius() {
    return this->radius;
}

int Ball::ColideBlock(IBlock & block) {
    int blockLeftX = block.getX();
    int blockRightX = blockLeftX + block.getWidth();
    int blockTopY = block.getY();
    int blockBottomY = blockTopY + block.getHeight();

    float ballCenterX = this->posX + this->radius;
    float ballCenterY = this->posY + this->radius;

    float closestX = std::max((float)blockLeftX, std::min(ballCenterX, (float)blockRightX));
    float closestY = std::max((float)blockTopY, std::min(ballCenterY, (float)blockBottomY));

    float distanceX = ballCenterX - closestX;
    float distanceY = ballCenterY - closestY;
    float distanceSquared = std::pow(distanceX, 2) + std::pow(distanceY, 2);

    if (distanceSquared <= std::pow(this->radius, 2)) {
        float overlapX = this->radius - std::abs(distanceX);
        float overlapY = this->radius - std::abs(distanceY);

        bool hitCorner = (ballCenterX < blockLeftX || ballCenterX > blockRightX) &&
                         (ballCenterY < blockTopY || ballCenterY > blockBottomY);

        if (hitCorner && std::abs(overlapX - overlapY) < (this->radius * 0.3f)) {
            if (this->verticalSpeed < 0)  {
                float oldVerticalSpeed = this->verticalSpeed;
                float oldHorysontalSpeed = this->horysontalSpeed;

                this->setSpeed(45);

                if (oldHorysontalSpeed > 0) {
                    this->horysontalSpeed = -this->horysontalSpeed;
                }
                if (oldVerticalSpeed > 0) {
                    this->verticalSpeed = -this->verticalSpeed;
                }
            }
            this->verticalSpeed = -this->verticalSpeed;
            this->horysontalSpeed = -this->horysontalSpeed;
        }
        else if (overlapX < overlapY) {
            if (distanceX < 0 && this->horysontalSpeed > 0) {
                this->horysontalSpeed = -horysontalSpeed;
            }
            else if (distanceX > 0 && this->horysontalSpeed < 0) {
                this->horysontalSpeed = -horysontalSpeed;
            }
        }
        else {
            if (distanceY < 0 && this->verticalSpeed > 0) {
                this->verticalSpeed = -this->verticalSpeed;
            }
            else if (distanceY > 0 && this->verticalSpeed < 0) {
                this->verticalSpeed = -this->verticalSpeed;
            }
        }
        
        return block.getID();
    }

    return -1;
}

