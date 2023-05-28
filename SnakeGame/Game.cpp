#include "Game.h"
#include "Graphics.h"
#include "Snake.h"
#include "Config.h"
#include "random"


Game::Game() {
    graphics = new Graphics(this);
    snake = new Snake(this);
    
    GridXCount = Config::WINDOW_WIDTH / Config::GRID_SIZE;
    GridYCount = Config::WINDOW_HEIGHT / Config::GRID_SIZE;

    std::random_device rd;
    generator = std::mt19937(rd());
}

Game::~Game() {
    delete graphics;
    delete snake;
}

void Game::Start() {
    // Реализация метода Start
}

void Game::Update() {
    //TODO: if snake eats food

    if (foods.size() < Config::FOOD_AMOUNT_ON_SCREEN) {
        int count = Config::FOOD_AMOUNT_ON_SCREEN - foods.size();
        for (size_t i = 0; i < count; i++)
        {
            SpawnFood();
        }
    }

    snake->Move();
    graphics->Draw();
}
void Game::SpawnFood() {
    std::uniform_int_distribution<int> distributionX(0, GridXCount);
    std::uniform_int_distribution<int> distributionY(0, GridYCount);
    //TODO: algo where get all avaiable cells and random by them


    int x = distributionX(generator);
    int y = distributionY(generator);

    foods.push_back({x,y});
    //TODO: Check if this not snake point
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
