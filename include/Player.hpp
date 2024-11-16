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

    #define BEAM_NUMBER 128
    #define CHECK_LENGTH 1.0f

    #define TOTAL_BEAMS BEAM_NUMBER * 2
    #define STRIPS_WIDTH 1200.0f / TOTAL_BEAMS
    #define SCALE_CONST 800.0f * 100.0f

    enum direction_move {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

class Player {
    public:
        Player();

        // * Up view
        void render(sf::RenderWindow &window) const;
        void move(direction_move direction);
        void update();

        // *Player Pov
        void PlayerRender();
        void PlayerUpdate();
        void drawWalls(sf::RenderWindow &window);

    private:
        // * Up view
        sf::CircleShape _skin;
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

        // * Player Pov
        std::vector<float> _raysDistance;
        float _scaleFactor;

        void getRaysDistance();
};
