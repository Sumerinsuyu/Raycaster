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

    enum direction_move {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

class Player {
    public:
        Player();
        sf::Vector2f getPos();
        void setPos(sf::Vector2f pos);
        float getDirection();
        void setDirection();
        sf::CircleShape getSkin();
        void setSkin(sf::CircleShape skin);
        float getFov();
        void setFov();
        sf::Vertex getDirectionVertex();
        void setDirectionVectex();

        void render(sf::RenderWindow &window);
        void move(direction_move direction);

    private:
        sf::Vector2f _pos;
        float _direction;
        sf::CircleShape _skin;
        float _fovAngle;
        sf::VertexArray _directionVertex;
        sf::VertexArray _fovVertex;          //declaring this make the player dissapear
        float _speed;
        float _camSpeed;

        void rotate(bool isRight);
        void movePlayer(bool isUp);
};
