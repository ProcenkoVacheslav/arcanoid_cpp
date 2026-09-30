cmake_minimum_required(VERSION 3.15)

project(arcanoid_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

set(SOURCES
    main.cpp
    src/application.cpp
    include/Constants.hpp
    include/carete.hpp
    src/carete.cpp
    include/ball.hpp
    src/ball.cpp
    include/blocks.hpp
    src/blocks.cpp
    include/gift.hpp
    src/gift.cpp
)

add_executable(arcanoid_cpp ${SOURCES})

target_link_libraries(arcanoid_cpp SFML::Graphics SFML::Window SFML::System)
