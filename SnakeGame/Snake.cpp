#include "Snake.h"
#include "Game.h"

//ctor with grid info and logic where snake change position
Snake::Snake(Game* game) {
    this->game = game;

    int gridXCount = Config::WINDOW_WIDTH / Config::GRID_SIZE;
    int gridYCount = Config::WINDOW_HEIGHT / Config::GRID_SIZE;

    Point startPoint = { gridXCount / 2, gridYCount / 2 };
    for (size_t i = 0; i < Config::SNAKE_START_SIZE; i++)
    {
        SnakeCells.push_back(startPoint);
        startPoint.x++;
    }
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

    Point currentHead = SnakeCells.front();
    SnakeCells.insert(SnakeCells.begin(), { currentHead.x + xMove, currentHead.y + yMove });

    bool isIncrease = false;
    Point head = GetHead();
    for (size_t i = 0; i < game->Foods.size(); ++i) {
        Point& foodPoint = game->Foods[i];

        if (head.x == foodPoint.x && head.y == foodPoint.y) {
            isIncrease = true;
            game->Foods.erase(game->Foods.begin() + i);
            break;
        }
    }

    if (!isIncrease) {
        SnakeCells.pop_back();
    }

    Point& newHead = SnakeCells.front();

    if (newHead.x > game->GridXCount - 1)
        newHead.x = 0;

    if (newHead.x < 0)
        newHead.x = game->GridXCount - 1;

    if (newHead.y > game->GridYCount - 1)
        newHead.y = 0;

    if (newHead.y < 0)
        newHead.y = game->GridYCount - 1;

    for (size_t i = 0; i < SnakeCells.size(); ++i) {
        Point& point = SnakeCells[i];

        if (newHead.x == point.x && newHead.y == point.y) {
            game->Lose();
        }
    }

}

Point Snake::GetHead() {
    return SnakeCells.front();
}

Direction Snake::GetDirection() {
    return direction;
}