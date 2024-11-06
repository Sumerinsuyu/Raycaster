/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game()
    : _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Doom")
{

}

void Game::events()
{
    while(_window.pollEvent(_event)) {
        switch (_event.type) {
            case (sf::Event::Closed):
                _window.close();
                break;
            case (sf::Event::KeyPressed):
                _player.move(UP);
                break;
            default:
                break;
        }
    }
}

void Game::display()
{
    _window.clear();
    _map.render(_window);
    _player.render(_window);
    _window.display();
}

void Game::update() const
{

}

void Game::loop()
{
    while (_window.isOpen()) {
        events();
        update();
        display();
    }
}

Game &Game::getInstance()
{
    static Game instance;

    return instance;
}
