#pragma once

#include <vector>
#include "Point.h"
#include "Config.h"
#include "random"

class Graphics;
class Snake;

class Game {
private:
    Graphics* graphics;
    Snake* snake;
    std::vector<Point> foods;
    std::mt19937 generator;

public:
    int GridXCount;
    int GridYCount;

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