#include "Game.h"
#include "Graphics.h"
#include "Snake.h"
#include "Config.h"
#include "random"
#include <SFML/System.hpp>

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Snake game");
    graphics = new Graphics(this, window);
    _Snake = new Snake(this);
    
    GridXCount = Config::WINDOW_WIDTH / Config::GRID_SIZE;
    GridYCount = Config::WINDOW_HEIGHT / Config::GRID_SIZE;

    std::random_device rd;
    generator = std::mt19937(rd());
}

Game::~Game() {
    delete graphics;
    delete _Snake;
}

void Game::Start() {
    // Реализация логики начала игры

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Обработка клавиш WASD
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _Snake->ChangeDirection(Direction::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            _Snake->ChangeDirection(Direction::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            _Snake->ChangeDirection(Direction::Bottom);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            _Snake->ChangeDirection(Direction::Right);
        }

        if (updateClock.getElapsedTime().asMilliseconds() >= updateInterval.asMilliseconds())
        {
            Update(); // Вызываем метод Update
            graphics->Draw(); // Отрисовываем игровые объекты
            // Сбросьте таймер
            updateClock.restart();
        }
    }

    //graphics->Shutdown(); // Завершение работы с графикой
}

void Game::Update() {
    _Snake->Move();

    

    if (Foods.size() < Config::FOOD_AMOUNT_ON_SCREEN) {
        int count = Config::FOOD_AMOUNT_ON_SCREEN - Foods.size();
        for (size_t i = 0; i < count; i++)
        {
            SpawnFood();
        }
    }

    graphics->Draw();
}
void Game::SpawnFood() {
    //get list of all cells
    std::vector<Point> cells;
    for (int x = 0; x < GridXCount; x++)
    {
        for (int y = 0; y < GridYCount; y++)
        {
            cells.push_back({ x, y });
        }
    }
    //filter cells
    for (size_t i = 0; i < _Snake->SnakeCells.size(); ++i) {
        Point& point = _Snake->SnakeCells[i];

        auto it = std::find(cells.begin(), cells.end(), point);
        int index = -1;
        if (it != cells.end()) {
            index = std::distance(cells.begin(), it);
        }

        if(index != -1)
            cells.erase(cells.begin() + index);
    }

    if (cells.size() == 0) {
        Win();
    }

    //random select from available and push new food
    std::uniform_int_distribution<int> distribution(0, cells.size()-1);
    int i = distribution(generator);
    Foods.push_back({ cells[i].x, cells[i].y });

}

void Game::Pause() {
    // Реализация метода Pause
}

void Game::Lose() {
    // Реализация метода Lose
}

void Game::End() {
    // Реализация метода End
}

void Game::Win() {
    // Реализация метода Win
}
