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

    #include "GameParameter.hpp"
    #include "Map.hpp"
    #include "Player.hpp"
    #include "Rendering3d.hpp"

class Game {
    public:
        static Game &getInstance();
        void loop();

    private:
        Player _player;
        Rendering3d _rendering3d;

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
