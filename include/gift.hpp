#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class IGift {
protected:

public:
    IGift();
    virtual ~IGift() = 0;

    void virtual Blit(sf::RenderWindow & window) = 0;
};

class Shild : public IGift {
private:
    bool isDestroy = false;
public:
    void Blit(sf::RenderWindow & window) override;
};

