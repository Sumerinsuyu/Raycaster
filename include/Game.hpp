/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Core.h
*/

#ifndef GAME_HPP
    #define GAME_HPP

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <map>
    #include <array>
    #include <SFML/Graphics.hpp>
    #include <math.h>

    #include "Map.hpp"
    #include "Player.hpp"

    #define SCREEN_WIDTH 1200
    #define SCREEN_HEIGHT 800


class Game {
    public:
        static Game &getInstance();
        void loop();

    private:
        Player _player;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock _clock;

        sf::RenderWindow _playerWindow;
        sf::Event _playerEvent;

        Game();
        // ~Game();

        void events();
        void update();
        void display();

        void setKey();
};

#endif
