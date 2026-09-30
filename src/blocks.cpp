#include "../include/blocks.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

//  IBLOCK

int IBlock::ID_COUNTER = 0;

IBlock::IBlock(int posX, int posY, int width, int height, sf::Color color)
 : blockObject(sf::Vector2f{static_cast<float>(width), static_cast<float>(height)}) {
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    this->color = color;

    blockObject.setPosition(sf::Vector2f{static_cast<float>(this->posX), static_cast<float>(this->posY)});
    blockObject.setFillColor(this->color);

    this->ID = ID_COUNTER;
    ID_COUNTER++;
}

int IBlock::getX() {
    return this->posX;
}

int IBlock::getY() {
    return this->posY;
}

int IBlock::getWidth() {
    return this->width;
}

int IBlock::getHeight() {
    return this->height;
}

int IBlock::getID() {
    return this->ID;
}

// SimpleBlock

SimpleBlock::SimpleBlock(int posX, int posY, int width, int height, sf::Color color) 
 : IBlock(posX, posY, width, height, color) {

}

void SimpleBlock::Blit(sf::RenderWindow & window) {
    window.draw(this->blockObject);
}

bool SimpleBlock::checkForDelete() {
    return true;
}

void SimpleBlock::DoStep() {

}

// Hard block
HardBlock::HardBlock(int posX, int posY, int width, int height, sf::Color startColor, sf::Color endColor) 
 : IBlock(posX, posY, width, height, startColor) {
    this->endColor = endColor; 
}

void HardBlock::Blit(sf::RenderWindow & window) {
    window.draw(this->blockObject);
}

bool HardBlock::checkForDelete() {
    return this->canDestroy;
}

void HardBlock::ChangeColor() {
    this->blockObject.setFillColor(this->endColor);
}

void HardBlock::DoStep() {
    this->ChangeColor();
    this->canDestroy = true;
}

// Indestructible Block
IndestructibleBlock::IndestructibleBlock(int posX, int posY, int width, int height, sf::Color color) 
 : IBlock(posX, posY, width, height, color) {

}

void IndestructibleBlock::Blit(sf::RenderWindow & window) {
    window.draw(this->blockObject);
}

bool IndestructibleBlock::checkForDelete() {
    return false;
}

void IndestructibleBlock::DoStep() {

}
