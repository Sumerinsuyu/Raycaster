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

void Game::setKey(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::W:
        _player.move(UP);
        break;
    case sf::Keyboard::S:
        _player.move(DOWN);
        break;
    case sf::Keyboard::A:
        _player.move(LEFT);
        break;
    case sf::Keyboard::D:
        _player.move(RIGHT);
        break;
    default:
        break;
    }
}

void Game::events()
{
    while(_window.pollEvent(_event)) {
        switch (_event.type) {
            case (sf::Event::Closed):
                _window.close();
                break;
            case (sf::Event::KeyPressed):
                setKey(_event);
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
