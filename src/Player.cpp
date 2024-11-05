/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player()
    : _pos{600.0f, 600.0f},
    _direction(0.0f),
    _skin(PLAYER_SIZE),
    _fov(60.0f)
{
    _skin.setOutlineColor(PLAYER_OUTLINE_COLOR);
    _skin.setFillColor(PLAYER_COLOR);
}