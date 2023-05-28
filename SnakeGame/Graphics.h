#pragma once
#include "Point.h"

class Game;

class Graphics {
private:
    Game* game;
    void drawHead(Point head);
    void drawBody(Point bodyPart);
    void drawFood(Point food);
    void drawGrid();

public:
    Graphics(Game* game);
    void Init();
    void Draw();
    void Shutdown();
};
