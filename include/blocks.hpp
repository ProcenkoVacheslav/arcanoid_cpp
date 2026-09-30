#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class IBlock {
protected:
    
    static int ID_COUNTER;

    int posX;
    int posY;
    int width;
    int height;
    sf::Color color;

    sf::RectangleShape blockObject;

    int ID;

public:
    IBlock(int posX, int posY, int width, int height, sf::Color color); 
    virtual ~IBlock() = default;

    void virtual Blit(sf::RenderWindow & window) = 0;
    bool virtual checkForDelete() = 0;
    void virtual DoStep() = 0;

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getID();
};

class SimpleBlock : public IBlock {
private:
    
public:
    SimpleBlock(int posX, int posY, int width, int height, sf::Color color);

    void Blit(sf::RenderWindow & window) override; 
    bool checkForDelete() override;
    void DoStep() override;
};

class HardBlock : public IBlock {
private:
    bool canDestroy = false;
    sf::Color endColor;
    
    void ChangeColor();

public:
    HardBlock(int posX, int posY, int width, int height, sf::Color startColor, sf::Color endColor);

    void Blit(sf::RenderWindow & window) override; 
    bool checkForDelete() override;
    void DoStep() override;
};

class IndestructibleBlock : public IBlock {
private:

public:
    IndestructibleBlock(int posX, int posY, int width, int height, sf::Color color);

    void Blit(sf::RenderWindow & window) override; 
    bool checkForDelete() override;
    void DoStep() override;
};

