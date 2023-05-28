#include "Graphics.h"
#include "Game.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

Graphics::Graphics(Game* game, sf::RenderWindow* window) {
    this->game = game;
    this->window = window;
}

void Graphics::Init() {
    
}

void Graphics::Draw() {
    sf::Color color = sf::Color(32, 33, 36);
    window->clear(color); // Очищаем окно

    // Рисуем змейку
    for (size_t i = 0; i < game->_Snake->SnakeCells.size(); ++i) {
        Point& point = game->_Snake->SnakeCells[i];

        if (i == 0)
            drawHead(point, game->_Snake->GetDirection());
        else
            drawBody(point);
    }
    
    // Рисуем еду
    for (size_t i = 0; i < game->Foods.size(); ++i) {
        Point& food = game->Foods[i];
        drawFood(food);
    }
    
    drawGrid(game->GridXCount, game->GridYCount);
    window->display(); // Отображаем содержимое окна
}

void Graphics::Shutdown() {
    window->close(); // Закрываем окно
}

void Graphics::drawHead(Point head, Direction direction) {
    sf::RectangleShape headShape(sf::Vector2f(Config::GRID_SIZE, Config::GRID_SIZE));
    headShape.setPosition(head.x * Config::GRID_SIZE, head.y * Config::GRID_SIZE);
    sf::Color color = sf::Color::Green;
    color.g = 200;
    headShape.setFillColor(color);
    window->draw(headShape);

    const int wTongueSize = 4;
    const int hTongueSize = Config::GRID_SIZE / 2;
    int xTongueSize = 0;
    int yTongueSize = 0;
    int xCellOffset = 0;
    int yCellOffset = 0;
    switch (direction)
    {
    case Direction::Up:
        xTongueSize = wTongueSize;
        yTongueSize = hTongueSize;
        xCellOffset = Config::GRID_SIZE / 2;
        yCellOffset = -Config::GRID_SIZE / 2;
        break;
    case Direction::Left:
        xTongueSize = hTongueSize;
        yTongueSize = wTongueSize;
        xCellOffset = -Config::GRID_SIZE / 2;
        yCellOffset = Config::GRID_SIZE / 2;
        break;
    case Direction::Right:
        xTongueSize = hTongueSize;
        yTongueSize = wTongueSize;
        xCellOffset = Config::GRID_SIZE;
        yCellOffset = Config::GRID_SIZE / 2;
        break;
    case Direction::Bottom:
        xTongueSize = wTongueSize;
        yTongueSize = hTongueSize;
        xCellOffset = Config::GRID_SIZE / 2;
        yCellOffset = Config::GRID_SIZE;
        break;
    }
    sf::RectangleShape tongue(sf::Vector2f(xTongueSize, yTongueSize));
    tongue.setPosition(head.x * Config::GRID_SIZE + xCellOffset, head.y * Config::GRID_SIZE + yCellOffset);
    tongue.setFillColor(sf::Color::Red);
    window->draw(tongue);
}

void Graphics::drawBody(Point point) {
    const int padding = 5;

    sf::RectangleShape bodyPart(sf::Vector2f(Config::GRID_SIZE - padding, Config::GRID_SIZE - padding));
    bodyPart.setPosition(point.x * Config::GRID_SIZE + (padding / 2), point.y * Config::GRID_SIZE + (padding / 2));
    bodyPart.setFillColor(sf::Color::Green);
    window->draw(bodyPart);
}
void Graphics::drawFood(Point food) {
    const int padding = 25; 

    sf::RectangleShape foodPiece(sf::Vector2f(Config::GRID_SIZE - padding, Config::GRID_SIZE - padding));
    foodPiece.setPosition(food.x * Config::GRID_SIZE + (padding/2), food.y * Config::GRID_SIZE + (padding / 2));
    foodPiece.setFillColor(sf::Color::Yellow);
    window->draw(foodPiece);
}

void Graphics::drawGrid(int gridXCount, int gridYCount) {
    sf::Color gridColor = sf::Color(100, 100, 100);
    const int width = 1;
    for (size_t i = 0; i < gridYCount; i++)
    {
        sf::RectangleShape line(sf::Vector2f(Config::WINDOW_WIDTH, width));
        line.setPosition(0, i * Config::GRID_SIZE);
        line.setFillColor(gridColor);
        window->draw(line);
    }

    for (size_t i = 0; i < gridXCount; i++)
    {
        sf::RectangleShape line(sf::Vector2f(width, Config::WINDOW_HEIGHT));
        line.setPosition(i * Config::GRID_SIZE, 0);
        line.setFillColor(gridColor);
        window->draw(line);
    }
}