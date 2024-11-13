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

    #define BEAM_NUMBER 8

    #define CHECK_LENGTH 10.0f

    enum direction_move {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

class Player {
    public:
        Player();

        void render(sf::RenderWindow &window) const;
        void move(direction_move direction);
        void update();

        void setCheckerPos(sf::Vector2f pos);

    private:
        sf::CircleShape _skin;
        sf::CircleShape _checker;
        sf::Vector2f _pos;
        sf::Vector2f _direction;
        float _fovAngle;
        sf::VertexArray _directionVertex;
        sf::VertexArray _fovVertex;
        float _speed;
        float _camSpeed;
        std::vector<sf::VertexArray> _beamArray;

        void rotate(bool isRight, sf::Vector2f &endPoint) const;
        void movePlayer(bool isUp, sf::Vector2f &base, sf::Vector2f &endPoint) const;
        void setPlayerFov();
        sf::VertexArray createBeam(float angle) const;
        void sendBeam();
        void checkBeamImpact();
};
