#pragma once

#include <vector>
#include "Point.h"

enum class Direction { Up, Left, Right, Bottom };
class Game;
class Snake {

private:
    Game* game;
    Direction direction;

public:
    std::vector<Point> SnakeCells;
    Snake(Game* game);
    void ChangeDirection(Direction direction);
    void Move();
    Point GetHead();
    Direction GetDirection();
};