/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include <cmath>

Player::Player()
    : _pos{600.0f, 600.0f},
    _direction(0.0f),
    _skin(PLAYER_SIZE),
    _fov(60.0f),
    _directionVertex(sf::Lines, 2),
    _speed(2.0f),
    _camSpeed(1.0f * M_PI / 180.0f)
{
    _skin.setOrigin({PLAYER_SIZE, PLAYER_SIZE});
    _skin.setOutlineColor(PLAYER_OUTLINE_COLOR);
    _skin.setFillColor(PLAYER_COLOR);
    _skin.setPosition(_pos);
    sf::Vertex player = _pos;
    sf::Vertex direction = sf::Vertex({_pos.x, _direction});
    _directionVertex[0] = player;
    _directionVertex[1] = direction;
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(_skin);
    window.draw(_directionVertex);
}

sf::Vector2f Player::getPos()
{
    return _pos;
}

void Player::setPos(sf::Vector2f pos)
{
    _pos = pos;
}

void Player::rotate()
{
    sf::Vector2f &pos = _directionVertex[1].position;
    // std::vector<std::vector<float>> matrix =
    // {
    //     {cos(_camSpeed), -sin(_camSpeed)},
    //     {sin(_camSpeed), cos(_camSpeed)}
    // };
    std::cout << _directionVertex[1].position.x << " " << _directionVertex[1].position.y << std::endl;
    std::cout << pos.x << " " << pos.y << std::endl;

    pos = {
        pos.x * std::cos(_camSpeed) - pos.y * std::sin(_camSpeed),
        pos.x * std::sin(_camSpeed) + pos.y * std::cos(_camSpeed)
    };

    // pos = {
    //     pos.x * matrix[0][0] + pos.y * matrix[0][1],
    //     pos.x * matrix[1][0] + pos.y * matrix[1][1]
    // };

    std::cout << _directionVertex[1].position.x << " " << _directionVertex[1].position.y << std::endl;
    std::cout << "BOUH" << std::endl;
}

void Player::move(direction_move direction)
{
    switch (direction)
    {
        case UP:
            rotate();
            break;
        case DOWN:

            break;
        case LEFT:

            break;
        case RIGHT:

            break;
        default:
            break;
    }
}
