#include "../include/carete.hpp"
#include "../include/Constants.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Carete::Carete(int startPosX, int startPosY, int careteWidth, int careteHeight , sf::Color caretteColor, std::string movementType) 
    : careteObject(sf::Vector2f{static_cast<float>(careteWidth), static_cast<float>(careteHeight)}){
    this->posX = startPosX;
    this->posY = startPosY;
    this->width = careteWidth;
    this->height = careteHeight;
    this->color = caretteColor;
    this->movementType = movementType;

    careteObject.setPosition(sf::Vector2f{static_cast<float>(this->posX), static_cast<float>(this->posY)});
    careteObject.setFillColor(this->color);
}

bool Carete::canMoveLeft() {
    if (this->posX > 0) {
        return true;
    }
    return false;
}

bool Carete::canMoveRight() {
    if (this->posX + this->width < Constants::windowWidth) {
        return true;
    }
    return false;
}

sf::Keyboard::Key Carete::getLeftKey() {
    if (this->movementType == "ad") {
        return sf::Keyboard::Key::A;
    }
    return sf::Keyboard::Key::Left;
}

sf::Keyboard::Key Carete::getRightKey() {
    if (this->movementType == "ad") {
        return sf::Keyboard::Key::D;
    }
    return sf::Keyboard::Key::Right;
}

void Carete::moveLeft() {
    if (sf::Keyboard::isKeyPressed(this->getLeftKey())) {
        if (this->canMoveLeft()) {
            this->posX -= this->SPEED;
        }
    }
}

void Carete::moveRight() {
    if (sf::Keyboard::isKeyPressed(this->getRightKey())) {
        if (this->canMoveRight()) {
            this->posX += this->SPEED;
        }
    }
}

void Carete::Move() {
    this->careteObject.setPosition(sf::Vector2f(static_cast<float>(this->posX), static_cast<float>(this->posY)));
    moveRight();
    moveLeft();
}

void Carete::Blit(sf::RenderWindow & Window) {
    Window.draw(this->careteObject);
}

int Carete::getWidth() {
    return this->width;
}

int Carete::getHeight() {
    return this->height;
}

int Carete::getPosX() {
    return this->posX;
}

int Carete::getPosY() {
    return this->posY; 
}
