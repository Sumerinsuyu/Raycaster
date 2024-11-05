/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Map.hpp
*/

// TODO : file parsing for dynamic maps

#ifndef MAP_HPP
    #define MAP_HPP

    #include <array>
    #include <SFML/Graphics.hpp>

    // * Map size
    #define MAP_WIDTH 24
    #define MAP_HEIGHT 24
    #define TILE_SIZE 50.0f

    // * Map blocks:
    enum blockType {
        EMPTY,
        BLUE_WALL,
        GREEN_WALL,
        RED_WALL,
        YELLOW_WALL
    };
    // * Typedef map
    using worldLine = std::array<blockType, MAP_WIDTH>;
    using world = std::array<worldLine, MAP_HEIGHT>;

class Map {
    public:
        Map();
        world &getMap();
        // TODO: void setMap();
        void render(sf::RenderWindow &window);

    private:
        world _worldMap;
        sf::RectangleShape _rectangle;
        void drawTile(sf::RenderWindow &window, int x, int y, blockType type);
};

#endif
