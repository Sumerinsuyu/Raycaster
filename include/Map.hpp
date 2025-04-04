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
    #include "GameParameter.hpp"

    // * Map blocks:
    enum blockType {
        EMPTY,
        BLUE_WALL,
        GREEN_WALL,
        RED_WALL,
        YELLOW_WALL
    };

    struct Block {
        blockType type;
        bool isHit = false;

        explicit Block(blockType bType): type(bType)
        {}
    };

    // * Typedef map
    using worldLine = std::array<Block, MAP_WIDTH>;
    using world = std::array<worldLine, MAP_HEIGHT>;

class Map {
    public:
        static Map &getInstance();
        world &getMap();
        // TODO: void setMap();
        void render(sf::RenderWindow &window);

    private:
        Map();
        world _worldMap;
        sf::RectangleShape _rectangle;
        void drawTile(sf::RenderWindow &window, int x, int y, blockType type);
        void resetMap();
};

#endif
