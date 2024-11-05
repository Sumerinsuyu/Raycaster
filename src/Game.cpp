/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Game.cpp
*/

#include "../include/Game.h"

Game::Game()
    : _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Doom")
{

}

void Game::events()
{
    while(_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::display()
{

}

void Game::update()
{

}

void Game::loop()
{
    while (_window.isOpen()) {
        events();
    }
}

Game &Game::getInstance()
{
    static Game instance;

    return instance;
}
