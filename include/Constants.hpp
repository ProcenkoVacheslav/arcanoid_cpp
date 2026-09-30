#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace Constants {
    // window
    inline constexpr int windowWidth = 800;
    inline constexpr int windowHeight = 800;
    inline const std::string windowTitle = "Arcanoid cpp";
    inline constexpr int FPS = 60;
    
    inline constexpr sf::Vector2u windowSize = {windowWidth, windowHeight};

    // carete
    inline constexpr int careteWidth = 120;
    inline constexpr int careteHeight = 20;
    inline constexpr int careteStartPosX = (windowWidth - careteWidth) / 2;
    inline constexpr int careteStartPosY = windowHeight - 10 - careteHeight; 
    inline constexpr int careteSpeed = 8;
    inline constexpr sf::Color careteColor = sf::Color(0, 255, 0);
    inline const std::string careteMovement = "lr";

    // ball
    inline constexpr int ballRadius = 15;
    inline constexpr float ballStartPosX = static_cast<float>(careteStartPosX);
    inline constexpr float ballStarttPosY = static_cast<float>(windowHeight * 3 / 4);
    inline constexpr float ballSpeed = 7.5;
    inline constexpr sf::Color ballColor = sf::Color(255, 0, 0);
    inline constexpr int ballMinAngle = 10;
    inline constexpr int ballMaxAngle = 170;

    // blocks
    inline constexpr int blockWidth = 40;
    inline constexpr int blockHeight = 40;
    inline constexpr int blockGap = 10;
    inline constexpr sf::Color blockColor = sf::Color(0, 0, 255);
    inline constexpr sf::Color seconsBlockColor = sf::Color(100, 0, 100);
    inline constexpr sf::Color thirdBlockColor = sf::Color(100, 200, 100);
}
