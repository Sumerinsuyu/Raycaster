/*
** EPITECH PROJECT, Block(GREEN_WALL)Block(EMPTY)Block(GREEN_WALL)Block(YELLOW_WALL)
** Doom
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include <ranges>
#include <iostream>
#include "Game.hpp"

Map::Map()
    : _worldMap
    {
        worldLine{Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(GREEN_WALL),Block(GREEN_WALL),Block(GREEN_WALL),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(GREEN_WALL),Block(GREEN_WALL),Block(EMPTY),Block(GREEN_WALL),Block(GREEN_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(RED_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(YELLOW_WALL),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(EMPTY),Block(BLUE_WALL)},
        worldLine{Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL),Block(BLUE_WALL)}
    },
    _rectangle({
        (SCREEN_WIDTH / MAP_WIDTH),
        (SCREEN_HEIGHT / MAP_HEIGHT)
    })
{
    // _rectangle.getOutlineThickness()
}

Map &Map::getInstance()
{
    static Map instance;

    return instance;
}

world &Map::getMap()
{
    return _worldMap;
}

void Map::render(sf::RenderWindow &window)
{
    for (auto [y, line] : std::views::enumerate(_worldMap)) {
        for (auto [x, tile]: std::views::enumerate(line)) {
            if (!tile.isHit)
                continue;
            drawTile(
                window,
                x * (SCREEN_WIDTH / MAP_WIDTH),
                y * (SCREEN_HEIGHT / MAP_HEIGHT),
                tile.type
            );
        }
    }
    resetMap();
}

void Map::drawTile(sf::RenderWindow &window, int x, int y, blockType type)
{
    sf::Color color{};

    _rectangle.setPosition({(float)x, (float)y});
    switch (type) {
        case EMPTY:
            color = sf::Color::Black;
            break;
        case BLUE_WALL:
            color = sf::Color::Blue;
            break;
        case GREEN_WALL:
            color = sf::Color::Green;
            break;
        case RED_WALL:
            color = sf::Color::Red;
            break;
        case YELLOW_WALL:
            color = sf::Color::Yellow;
            break;
    }
    _rectangle.setFillColor(color);
    window.draw(_rectangle);
}

void Map::resetMap()
{
    for (auto &line: _worldMap) {
        for (auto &block : line) {
            block.isHit = false;
        }
    }
}
