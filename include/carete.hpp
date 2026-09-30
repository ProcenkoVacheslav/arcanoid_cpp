#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

#include "Constants.hpp"

class Carete {
private:
    int posX;
    int posY;
    int width;
    int height;
    sf::Color color;
    std::string movementType; // ad, left right - lr

    sf::RectangleShape careteObject;
                            
    const int SPEED = Constants::careteSpeed;

    bool canMoveLeft(); 
    bool canMoveRight(); 

    sf::Keyboard::Key getLeftKey();
    sf::Keyboard::Key getRightKey();

    void moveLeft();
    void moveRight();
public:
    Carete(int startPosX, int startPosY, int careteWidth, int careteHeight , sf::Color caretteColor, std::string movementType = "ad");
    ~Carete() = default;

    void Move();
    void Blit(sf::RenderWindow & Window);

    int getWidth();
    int getHeight();
    int getPosX();
    int getPosY();
};

