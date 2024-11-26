/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game()
    : _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Doom"),
    _playerWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PlayerPov"),
    _playerEvent()
{
    _window.setFramerateLimit(60);
    _playerWindow.setFramerateLimit(60);
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
    while (_playerWindow.pollEvent(_playerEvent));
    setKey();
}

void Game::display()
{
    _window.clear();
    _playerWindow.clear();
    Map::getInstance().render(_window);
    _player.render(_window);
    _rendering3d.render(_playerWindow, _player.getRayDistance());
    _window.display();
    _playerWindow.display();
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
