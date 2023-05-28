#pragma once

#include <vector>
#include "Point.h"

enum class Direction { Up, Left, Right, Bottom };
class Game;
class Snake {

private:
    Game* game;
    std::vector<Point> snakeCells;
    Direction direction;
    bool nextMoveIncreaseSize;

public:
    Snake(Game* game);
    void ChangeDirection(Direction direction);
    void Move();
    Point GetHead();
    void IncreaseSize();
};