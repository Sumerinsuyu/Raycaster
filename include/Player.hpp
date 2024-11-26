/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.hpp
*/

#pragma once

    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include "GameParameter.hpp"

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
        std::vector<float> getRayDistance() const;
        void render(sf::RenderWindow &window) const;
        void move(direction_move direction);
        void update();

    private:
        // * Up view
        sf::CircleShape _skin;
        sf::Vector2f _pos;
        sf::Vector2f _direction;
        float _fovAngle;
        sf::VertexArray _directionVertex;
        std::pair<sf::VertexArray, float> _fovVertex;
        float _speed;
        float _camSpeed;
        std::vector<std::pair<sf::VertexArray, float>> _beamArray;

        void rotate(bool isRight, sf::Vector2f &endPoint) const;
        void movePlayer(bool isUp, sf::Vector2f &base, sf::Vector2f &endPoint) const;
        void setPlayerFov();
        sf::VertexArray createBeam(float angle) const;
        void sendBeam();
        void checkBeamImpact();

        // * Player Pov
        std::vector<float> _raysDistance;
        void computeRaysDistance();
};
