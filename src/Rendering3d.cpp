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
#include <cmath>

Rendering3d::Rendering3d()
: _floorTexture()
{
    _floorTexture.loadFromFile("./asset/floor.png");
    _floorImage = _floorTexture.copyToImage();
    _renderedImage.create(SCREEN_WIDTH, (SCREEN_HEIGHT / 2.0f));
}

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
        wall.setPosition({i * STRIPS_WIDTH / 2, SCREEN_HEIGHT / 2});
        wall.setSize({STRIPS_WIDTH, wallHeight});
        wall.setFillColor(color);
        window.draw(wall);
        ++i;
    }
}

void Rendering3d::renderFloor(sf::RenderWindow &window, sf::Vector2f plane,
    sf::Vector2f direction, sf::Vector2f playerPos)
{
    float rayDirX0{};
    float rayDirY0{};
    float rayDirX1{};
    float rayDirY1{};
    float horizonPos{};
    float rowDistance{};
    float floorStepX{};
    float floorStepY{};
    float posX = (playerPos.x * ((float)MAP_WIDTH / SCREEN_WIDTH));
    float posY = (playerPos.y * ((float)MAP_HEIGHT / SCREEN_HEIGHT));
    float floorX{};
    float floorY{};

    _renderedImage.create(SCREEN_WIDTH, (SCREEN_HEIGHT / 2.0f));

    for (int y = SCREEN_HEIGHT / 2 + 1; y < SCREEN_HEIGHT; y++) {
        rayDirX0 = direction.x - plane.x;
        rayDirY0 = direction.y - plane.y;
        rayDirX1 = direction.x + plane.x;
        rayDirY1 = direction.y + plane.y;

        horizonPos = (float)y - SCREEN_HEIGHT / 2.0f;

        rowDistance = POS_Z / horizonPos * 2.0f;

        floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
        floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;

        floorX = posX + rowDistance * rayDirX0;
        floorY = posY + rowDistance * rayDirY0;

        for (int x = 0; x < SCREEN_WIDTH; x++) {
            int cellX = floorX;
            int cellY = floorY;

            int tx = (int)(FLOOR_WIDTH * (floorX - cellX)) & (FLOOR_WIDTH - 1);
            int ty = (int)(FLOOR_HEIGHT * (floorY - cellY)) & (FLOOR_HEIGHT - 1);

            floorX += floorStepX;
            floorY += floorStepY;

            sf::Color color = _floorImage.getPixel(tx, ty);

            _renderedImage.setPixel(x, (y - (int)(SCREEN_HEIGHT / 2.0f)), color);
        }
    }
    _renderedFloorTexture.loadFromImage(_renderedImage);
    _renderedFloorSprite.setTexture(_renderedFloorTexture);
    _renderedFloorSprite.setPosition({0.0f, SCREEN_HEIGHT / 2});
    window.draw(_renderedFloorSprite);
}

void Rendering3d::renderSky(sf::RenderWindow &window) const
{
    auto sky = sf::RectangleShape({SCREEN_WIDTH, SCREEN_HEIGHT / 2});

    sky.setFillColor(sf::Color(43, 44, 90, 255));
    window.draw(sky);
}

void Rendering3d::render(sf::RenderWindow &window,
    const std::vector<float> &rayDistance, [[maybe_unused]] const Player &player)
{
    renderSky(window);
    // renderFloor(window, player.getPlane(), player.getDirection(),
    //     player.getPosition());
    renderWalls(window, rayDistance);
}
