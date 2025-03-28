/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Game.cpp
*/

#include "Game.hpp"

Game::Game()
    : _player(),
    _rendering3d(),
    _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Raycasting"),
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
                _playerWindow.close();
                break;
            case sf::Event::KeyPressed:
                break;
            default:
                break;
        }
    }
    while (_playerWindow.pollEvent(_playerEvent)) {
        if (_playerEvent.type == sf::Event::Closed) {
            _window.close();
            _playerWindow.close();
        }
    }
    setKey();
}

void Game::display()
{
    _window.clear();
    _playerWindow.clear();
    Map::getInstance().render(_window);
    _player.render(_window);
    _rendering3d.render(_playerWindow, _player.getRayDistance(), _player);
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
