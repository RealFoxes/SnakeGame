#pragma once

#include <vector>
#include "Point.h"
#include "Config.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "random"

class Graphics;
class Snake;

class Game {
private:
    Graphics* graphics;
    sf::RenderWindow* window;
    bool isRunning;
    std::mt19937 generator;

    sf::Clock updateClock;
    sf::Time updateInterval = sf::milliseconds(Config::GAME_SPEED*100); // Интервал вызова метода Update() в миллисекундах

public:
    int GridXCount;
    int GridYCount;
    std::vector<Point> Foods;
    Snake* _Snake;

    Game();
    ~Game();

    void Start();
    void Update();
    void SpawnFood();
    void Pause();
    void Lose();
    void End();
    void Win();
};