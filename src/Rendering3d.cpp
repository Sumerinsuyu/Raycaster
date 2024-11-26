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
    std::vector<float> const &rayDistance) const
{
    sf::RectangleShape wall;
    float wallHeight;
    int i = 0;
    float brightness;
    sf::Color color;

    for (auto &distance: rayDistance) {
        wallHeight = (SCALE_CONST / distance);
        brightness = (SCREEN_WIDTH - distance) / SCREEN_WIDTH;
        color = sf::Color(brightness * 255, 0, 0, 255);
        wall.setOrigin({STRIPS_WIDTH / 2, wallHeight / 2});
        wall.setPosition({i * STRIPS_WIDTH / 2, SCREEN_WIDTH / 2});
        wall.setSize({STRIPS_WIDTH, wallHeight});
        wall.setFillColor(color);
        window.draw(wall);
        ++i;
    }
}

void Rendering3d::render(sf::RenderWindow &window,
    const std::vector<float> &rayDistance) const
{
    renderWalls(window, rayDistance);
}
