#include "../include/application.hpp"
#include "../include/Constants.hpp"
#include "../include/carete.hpp"
#include "../include/ball.hpp"
#include "../include/blocks.hpp"

#include <memory>
#include <optional>
#include <vector>

Application::Application() : mWindow(sf::VideoMode(Constants::windowSize), Constants::windowTitle) {
    mWindow.setFramerateLimit(Constants::FPS);
    mWindow.setVerticalSyncEnabled(true);
}    

void Application::processorEvents() {
    while (const std::optional event = mWindow.pollEvent()) {
        if (event->is<sf::Event::Event::Closed>()){
            mWindow.close();
        }
    }   
}

void Application::update() {
    mWindow.display();
}

void Application::fill() {
    mWindow.clear(sf::Color(100, 100, 100));
}

void Application::generateBlocks(std::vector<std::unique_ptr<IBlock>> & blocks) {
    int widthCount = Constants::windowWidth / (Constants::blockWidth + Constants::blockGap);
    for (int column = 0; column < 5; column++) {
        for (int row = 0; row < widthCount; row++) {
            blocks.push_back(std::make_unique<SimpleBlock>(
                Constants::blockGap / 2 + (Constants::blockWidth + Constants::blockGap) * row,
                Constants::blockGap / 2 + (Constants::blockHeight + Constants::blockGap) * column,
                Constants::blockWidth,
                Constants::blockHeight,
                Constants::blockColor
            ));
        }
    }
    for (int row = 0; row < widthCount; row++) {
        blocks.push_back(std::make_unique<HardBlock>(
            Constants::blockGap / 2 + (Constants::blockWidth + Constants::blockGap) * row,
            Constants::blockGap / 2 + (Constants::blockHeight + Constants::blockGap) * 5,
            Constants::blockWidth,
            Constants::blockHeight,
            Constants::seconsBlockColor,
            Constants::blockColor
        ));
    }
    for (int row = 0; row < widthCount; row += 3) {
        blocks.push_back(std::make_unique<IndestructibleBlock>(
            Constants::blockGap / 2 + (Constants::blockWidth + Constants::blockGap) * row,
            Constants::blockGap / 2 + (Constants::blockHeight + Constants::blockGap) * 6,
            Constants::blockWidth,
            Constants::blockHeight,
            Constants::thirdBlockColor
        ));
    }
}

void Application::deleteBlock(int blockID, std::vector<std::unique_ptr<IBlock>> & blocks) {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i]->getID() == blockID) {
            if (blocks[i]->checkForDelete()) {
                blocks.erase(blocks.begin() + i);
            }
            else {
                blocks[i]->DoStep();
            }
        }
    }
}

void Application::colideBlocks(std::vector<std::unique_ptr<IBlock>> & blocks, Ball & ball) {
    for (auto it = blocks.begin(); it != blocks.end(); ) {
        int result = ball.ColideBlock(**it);
        if (result != -1) {
            this->deleteBlock(result, blocks);
            break;
        }
        else {
            ++it;
        }
    } 
}

void Application::checkGame(std::vector<std::unique_ptr<IBlock>> & blocks, Ball & ball) {
    this->checkForWin(blocks);
    this->checkForLoose(ball);
}

void Application::checkForWin(std::vector<std::unique_ptr<IBlock>> & blocks) {
    if (blocks.size() == 0) {
        mWindow.close();
    }
    else {

    }
}

void Application::checkForLoose(Ball & ball) {
    if (ball.getPosY() + ball.getRadius() >= Constants::windowHeight) {
        mWindow.close();
    }
}

void Application::run() {
    Carete carete(
        Constants::careteStartPosX, 
        Constants::careteStartPosY, 
        Constants::careteWidth, 
        Constants::careteHeight, 
        Constants::careteColor,
        Constants::careteMovement 
    );

    Ball ball(
        Constants::ballStartPosX,
        Constants::ballStarttPosY,
        Constants::ballRadius,
        Constants::ballColor,
        70 
    );

    std::vector<std::unique_ptr<IBlock>> blocks;
    this->generateBlocks(blocks);

    while (mWindow.isOpen()) {
        processorEvents();
        carete.Move();
        ball.Move();

        ball.Colide(carete);
        this->colideBlocks(blocks, ball); 

        this->checkGame(blocks, ball);
        fill();

        carete.Blit(mWindow);
        ball.Blit(mWindow);

        for (const auto & block : blocks) {
            block->Blit(mWindow); 
        }

        update();
    }
}
