/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include <cmath>

Player::Player()
    : _skin(PLAYER_SIZE),
    _pos{600.0f, 600.0f},
    _direction{},
    _fovAngle(60.0 * (M_PI / 180.0f)),
    _directionVertex(sf::Lines, 2),
    _fovVertex(sf::Lines, 4),
    _speed(3.0f),
    _camSpeed(2.0f * (M_PI / 180.0f))
{
    _skin.setOrigin({PLAYER_SIZE, PLAYER_SIZE});
    _skin.setOutlineColor(PLAYER_OUTLINE_COLOR);
    _skin.setFillColor(PLAYER_COLOR);
    _skin.setPosition(_pos);

    sf::Vertex player = _pos;
    sf::Vertex direction({_pos.x, 200.0f});
    _directionVertex[0] = player;
    _directionVertex[1] = direction;

    _direction = _directionVertex[1].position - _directionVertex[0].position;
    setPlayerFov();
}

void Player::render(sf::RenderWindow &window) const
{
    window.draw(_skin);
    window.draw(_directionVertex);
    window.draw(_fovVertex);
}

void Player::move(direction_move direction)
{
    switch (direction)
    {
        case UP:
            movePlayer(true, _directionVertex[0].position, _directionVertex[1].position);
            setPlayerFov();
            break;
        case DOWN:
            movePlayer(false, _directionVertex[0].position, _directionVertex[1].position);
            setPlayerFov();
            break;
        case LEFT:
            rotate(false, _directionVertex[1].position);
            rotate(false, _fovVertex[1].position);
            rotate(false, _fovVertex[3].position);
            break;
        case RIGHT:
            rotate(true, _directionVertex[1].position);
            rotate(true, _fovVertex[1].position);
            rotate(true, _fovVertex[3].position);
            break;
        default:
            break;
    }
}

void Player::update()
{
    _skin.setPosition(_directionVertex[0].position);
    _pos = _directionVertex[0].position;

    _direction = _directionVertex[1].position - _directionVertex[0].position;
}

void Player::rotate(bool isRight, sf::Vector2f &endPoint) const
{
    sf::Vector2f &pos = endPoint;
    sf::Vector2f playerRelativePos = pos - _pos;
    float direction = isRight ? _camSpeed : (-_camSpeed);

    playerRelativePos = {
        playerRelativePos.x * std::cos(direction) - playerRelativePos.y * std::sin(direction),
        playerRelativePos.x * std::sin(direction) + playerRelativePos.y * std::cos(direction)
    };
    pos = _pos + playerRelativePos;
}

void Player::movePlayer(bool isUp, sf::Vector2f &basePoint, sf::Vector2f &endPoint) const
{
    sf::Vector2f base = basePoint;
    sf::Vector2f tip = endPoint;
    sf::Vector2f dir = tip - base;
    float tempSpeed = isUp ? _speed : -_speed;
    float absDir = sqrt(
        pow(tip.x - base.x, 2.0f) + pow(tip.y - base.y, 2.0f)
    );
    sf::Vector2f newPoint = base + dir / absDir * tempSpeed;
    sf::Vector2f newEndPoint = base + dir / absDir * (400.0f + tempSpeed);

    basePoint = newPoint;
    endPoint = newEndPoint;
}

void Player::setPlayerFov()
{
    float planeLength = tan(_fovAngle / 2.0f);
    sf::Vector2f plane(-_direction.y * planeLength, _direction.x * planeLength);

    _fovVertex[1] = _pos + _direction - plane;
    _fovVertex[3] = _pos + _direction + plane;

    _fovVertex[0].position = _pos;
    _fovVertex[2].position = _pos;
}
