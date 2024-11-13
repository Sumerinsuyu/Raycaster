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
    _window.setFramerateLimit(60);
}

void Game::setKey()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _player.move(UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _player.move(DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _player.move(LEFT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _player.move(RIGHT);
}

void Game::events()
{
    while(_window.pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            case sf::Event::KeyPressed:
                break;
            default:
                break;
        }
    }
    setKey();
}

void Game::display()
{
    _window.clear();
    Map::getInstance().render(_window);
    _player.render(_window);
    _window.display();
}

void Game::update()
{
    _player.update();
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
