#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "blocks.hpp"
#include "ball.hpp"

class Application {
private:
    void update();
    void fill();
    void processorEvents();
    void render();

    void generateBlocks(std::vector<std::unique_ptr<IBlock>> & blocks);
    void deleteBlock(int blockID, std::vector<std::unique_ptr<IBlock>> & blocks);
    void colideBlocks(std::vector<std::unique_ptr<IBlock>> & blocks, Ball & ball);

    void checkGame(std::vector<std::unique_ptr<IBlock>> & blocks, Ball & ball);
    void checkForWin(std::vector<std::unique_ptr<IBlock>> & blocks);
    void checkForLoose(Ball & ball);
private:
    sf::RenderWindow mWindow;

public:
    Application();
    ~Application() = default;
    
    void run();
};
