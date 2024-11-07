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
    sf::Vertex direction = sf::Vertex({_pos.x, 0.0f});
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

void Player::rotate(bool isRight)
{
    sf::Vector2f &pos = _directionVertex[1].position;
    sf::Vector2f playerRelativePos = pos - _pos;
    float direction = isRight ? _camSpeed : (-_camSpeed);

    playerRelativePos = {
        playerRelativePos.x * std::cos(direction) - playerRelativePos.y * std::sin(direction),
        playerRelativePos.x * std::sin(direction) + playerRelativePos.y * std::cos(direction)
    };
    pos = _pos + playerRelativePos;
}

void Player::movePlayer()
{
    sf::Vector2f base = _directionVertex[0].position;
    sf::Vector2f tip = _directionVertex[1].position;
    sf::Vector2f dir = tip - base;
    float absDir = sqrt(
        pow(tip.x - base.x, 2.0f) + pow(tip.y - base.y, 2.0f)
    );
    sf::Vector2f new_point = base + dir / absDir * 50.0f;
    _skin.setPosition(new_point);
    _pos = new_point;
    _directionVertex[0].position = new_point;
    _directionVertex[1].position = tip;
}

void Player::move(direction_move direction)
{
    switch (direction)
    {
        case UP:
            movePlayer();
            break;
        case DOWN:

            break;
        case LEFT:
            rotate(false);
            break;
        case RIGHT:
            rotate(true);
            break;
        default:
            break;
    }
}
