/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Core.h
*/

#ifndef GAME_H
    #define GAME_H

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <map>
    #include <SFML/Graphics.hpp>

    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 600


class Game {
    public:
        static Game &getInstance();
        void loop();

    private:
        sf::Window _window;
        sf::Event _event;
        sf::Clock _clock;
        Game();
        // ~Game();

        void events();
        void update();
        void display();
};

#endif