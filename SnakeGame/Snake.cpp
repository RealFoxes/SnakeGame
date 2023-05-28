#include "Snake.h"
#include "Game.h"

//ctor with grid info and logic where snake change position
Snake::Snake(Game* game) {
    this->game = game;
}

void Snake::ChangeDirection(Direction direction) {
    this->direction = direction;
}

void Snake::Move() {
    int xMove = 0;
    int yMove = 0;

    switch (direction)
    {
    case Direction::Up:
        yMove = -1;
        break;
    case Direction::Left:
        xMove = -1;
        break;
    case Direction::Right:
        xMove = 1;
        break;
    case Direction::Bottom:
        yMove = 1;
        break;
    }

    Point currentHead = snakeCells.front();
    snakeCells.insert(snakeCells.begin(), { currentHead.x + xMove, currentHead.y + yMove });
    if (!nextMoveIncreaseSize) {
        snakeCells.pop_back();
        nextMoveIncreaseSize = false;
    }

    Point& newHead = snakeCells.front();

    if (newHead.x > game->GridXCount)
        newHead.x = 0;

    if (newHead.x < 0)
        newHead.x = game->GridXCount;

    if (newHead.y > game->GridYCount)
        newHead.y = 0;

    if (newHead.y < 0)
        newHead.y = game->GridYCount;

    for (size_t i = 0; i < snakeCells.size(); ++i) {
        Point& point = snakeCells[i];

        if (newHead.x == point.x && newHead.y == point.y) {
            game->Lose();
        }
    }

}

Point Snake::GetHead() {
    return snakeCells.front();
}

void Snake::IncreaseSize() {
    nextMoveIncreaseSize = true;
}
