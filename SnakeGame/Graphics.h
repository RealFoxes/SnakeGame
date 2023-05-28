#pragma once
#include "Point.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Game;

class Graphics {
private:
    Game* game;
    sf::RenderWindow* window;
    void drawHead(Point head, Direction direction);
    void drawBody(Point bodyPart);
    void drawFood(Point food);
    void drawGrid(int gridXCount, int gridYCount);

public:
    Graphics(Game* game, sf::RenderWindow* window);
    void Init();
    void Draw();
    void Shutdown();
};
