/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Nov, 2024                                                     *
 * Title           - Doom                                                               *
 * Description     -                                                                    *
 *     Rendering3d                                                                      *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Rendering3d.hpp"

void Rendering3d::renderWalls(sf::RenderWindow &window,
    std::vector<float> rayDistance) const
{
    sf::RectangleShape wall;
    float wallHeight;
    int i = 0;
    float brightness;
    sf::Color color;

    for (auto &distance: rayDistance) {
        wallHeight = (SCALE_CONST / distance);
        brightness = (1200.0f - distance) / 1200.0f;
        color = sf::Color(brightness * 255, 0, 0, 255);
        wall.setOrigin({STRIPS_WIDTH / 2, wallHeight / 2});
        wall.setPosition({i * STRIPS_WIDTH / 2, 400.0f});
        wall.setSize({STRIPS_WIDTH, wallHeight});
        wall.setFillColor(color);
        window.draw(wall);
        ++i;
    }
}
