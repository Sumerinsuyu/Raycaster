/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.hpp
*/

#pragma once

    #include <iostream>
    #include <SFML/Graphics.hpp>

    #define PLAYER_SIZE 20
    #define PLAYER_COLOR sf::Color::Red
    #define PLAYER_OUTLINE_COLOR sf::Color::White
    #define DIRECTION_COLOR sf::Color::Green

class Player {
    public:
        Player();

        void render(sf::RenderWindow &window);
    private:
        sf::Vector2f _pos;
        float _direction;
        sf::CircleShape _skin;
        float _fov;

        std::pair<float, float> getPos();
        void setPos(std::pair<float, float>);
        float getDirection();
        void setDirection();
        sf::CircleShape getSkin();
        void setSkin(sf::CircleShape skin);
        float getFov();
        void setFov();
};
