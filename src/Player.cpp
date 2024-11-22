/*
** EPITECH PROJECT, 2024
** Doom
** File description:
** Player.cpp
*/

#include <cmath>

#include "Player.hpp"
#include "Map.hpp"

Player::Player()
    : _skin(PLAYER_SIZE),
    _pos{600.0f, 600.0f},
    _direction{},
    _fovAngle(60.0 * (M_PI / 180.0f)),
    _directionVertex(sf::Lines, 2),
    _fovVertex(sf::Lines, 4),
    _speed(3.0f),
    _camSpeed(1.2f * (M_PI / 180.0f)),
    _beamArray(),
    _raysDistance()
{
    _skin.setOrigin({PLAYER_SIZE, PLAYER_SIZE});
    _skin.setOutlineColor(PLAYER_OUTLINE_COLOR);
    _skin.setFillColor(PLAYER_COLOR);
    _skin.setPosition(_pos);

    sf::Vertex player = _pos;
    sf::Vertex direction({_pos.x, -600.0f});
    _directionVertex[0] = player;
    _directionVertex[1] = direction;

    _direction = _directionVertex[1].position - _directionVertex[0].position;
    setPlayerFov();
    sendBeam();
}

void Player::render(sf::RenderWindow &window) const
{
    window.draw(_skin);
    window.draw(_directionVertex);
    window.draw(_fovVertex);
    for (auto &beam: _beamArray)
        window.draw(beam);
}

void Player::move(direction_move direction)
{
    switch (direction)
    {
        case UP:
            movePlayer(true, _directionVertex[0].position, _directionVertex[1].position);
            setPlayerFov();
            break;
        case DOWN:
            movePlayer(false, _directionVertex[0].position, _directionVertex[1].position);
            setPlayerFov();
            break;
        case LEFT:
            rotate(false, _directionVertex[1].position);
            rotate(false, _fovVertex[1].position);
            rotate(false, _fovVertex[3].position);
            break;
        case RIGHT:
            rotate(true, _directionVertex[1].position);
            rotate(true, _fovVertex[1].position);
            rotate(true, _fovVertex[3].position);
            break;
        default:
            break;
    }
}

void Player::update()
{
    _skin.setPosition(_directionVertex[0].position);
    _pos = _directionVertex[0].position;
    _direction = _directionVertex[1].position - _directionVertex[0].position;
    sendBeam();
    checkBeamImpact();
    getRaysDistance();
}

void Player::rotate(bool isRight, sf::Vector2f &endPoint) const
{
    sf::Vector2f &pos = endPoint;
    sf::Vector2f playerRelativePos = pos - _pos;
    float direction = isRight ? _camSpeed : (-_camSpeed);

    playerRelativePos = {
        playerRelativePos.x * std::cos(direction) - playerRelativePos.y * std::sin(direction),
        playerRelativePos.x * std::sin(direction) + playerRelativePos.y * std::cos(direction)
    };
    pos = _pos + playerRelativePos;
}

void Player::movePlayer(bool isUp, sf::Vector2f &basePoint, sf::Vector2f &endPoint) const
{
    sf::Vector2f base = basePoint;
    sf::Vector2f tip = endPoint;
    sf::Vector2f dir = tip - base;
    float tempSpeed = isUp ? _speed : -_speed;
    float absDir = sqrt(
        pow(tip.x - base.x, 2.0f) + pow(tip.y - base.y, 2.0f)
    );
    sf::Vector2f newPoint = base + dir / absDir * tempSpeed;
    sf::Vector2f newEndPoint = base + dir / absDir * (1200.0f + tempSpeed);

    if (Map::getInstance().getMap()[(int)(newPoint.y * (24.0f / 800.0f))]
        [(int)(newPoint.x * (24.0f / 1200.0f))].type != EMPTY)
        return;
    basePoint = newPoint;
    endPoint = newEndPoint;
}

void Player::setPlayerFov()
{
    float planeLength = tan(_fovAngle / 2.0f);
    sf::Vector2f plane(-_direction.y * planeLength, _direction.x * planeLength);

    _fovVertex[1] = _pos + _direction - plane;
    _fovVertex[3] = _pos + _direction + plane;

    _fovVertex[0].position = _pos;
    _fovVertex[2].position = _pos;

    _fovVertex[0].color = sf::Color::Red;
    _fovVertex[1].color = sf::Color::Red;

    _fovVertex[2].color = sf::Color::Green;
    _fovVertex[3].color = sf::Color::Green;

}

sf::VertexArray Player::createBeam(float angle) const
{
    float planeLength = tan(angle / 2.0f);
    sf::Vector2f plane(-_direction.y * planeLength, _direction.x * planeLength);
    sf::VertexArray beam(sf::Lines, 4);

    beam[1] = _pos + _direction - plane;
    beam[3] = _pos + _direction + plane;

    beam[0].position = _pos;
    beam[2].position = _pos;

    beam[0].color = sf::Color::Yellow;
    beam[1].color = sf::Color::Yellow;

    beam[2].color = sf::Color::Magenta;
    beam[3].color = sf::Color::Magenta;

    return beam;
}

void Player::sendBeam()
{
    float beamAngle = _fovAngle;

    _beamArray.clear();
    for (int i = 0; i < BEAM_NUMBER; i++) {
        _beamArray.push_back(createBeam(beamAngle));
        beamAngle -= (_fovAngle / BEAM_NUMBER);
    }
}

sf::Vector2f getNewPoint(sf::VertexArray &currentCheck)
{
    sf::Vector2f base = currentCheck[0].position;
    sf::Vector2f tip = currentCheck[1].position;
    sf::Vector2f dir = tip - base;
    float absDir = sqrt(
        pow(tip.x - base.x, 2.0f) + pow(tip.y - base.y, 2.0f)
    );
    sf::Vector2f newPoint = base + dir / absDir * CHECK_LENGTH;

    return newPoint;
}

bool updateBeam(sf::VertexArray &beam, int firstPos, int secondPos)
{
    sf::Vector2f checkPoint = beam[firstPos].position;
    sf::VertexArray checkArray(sf::Lines, 2);
    sf::Vector2i testPoint;
    auto &map = Map::getInstance();

    checkArray[1].position = beam[secondPos].position;
    for (int i = 0; i < 1200 / CHECK_LENGTH; i++) {
        checkArray[0].position = checkPoint;
        checkPoint = getNewPoint(checkArray);
        testPoint = {(int)(checkPoint.x * (24.0f / 1200.0f)),
            (int)(checkPoint.y * (24.0f / 800.0f))};
        if (testPoint.y <= 24 && testPoint.x <= 24 &&
                map.getMap()[testPoint.y][testPoint.x].type != EMPTY) {
            beam[secondPos].position = checkPoint;
            Map::getInstance().getMap()[testPoint.y][testPoint.x].isHit = true;
            return true;
        }
    }
    return false;
}

void Player::checkBeamImpact()
{
    sf::Vector2f pos;

    for (auto &beam: _beamArray) {
        updateBeam(beam, 0, 1);
        updateBeam(beam, 2, 3);
    }
}

float getDistance(sf::Vector2f begin, sf::Vector2f end)
{
    return sqrt(pow(end.x - begin.x, 2) + pow(end.y - begin.y, 2));
}

void Player::getRaysDistance()
{
    _raysDistance.clear();
    for (auto riter = _beamArray.rbegin(); riter != _beamArray.rend(); ++riter) {
        _raysDistance.insert(_raysDistance.begin(),
            getDistance((*riter)[0].position, (*riter)[1].position));
        _raysDistance.push_back(
            getDistance((*riter)[2].position, (*riter)[3].position));
    }
}

void Player::drawWalls(sf::RenderWindow &window) const
{
    sf::RectangleShape wall;
    float wallHeight;
    int i = 0;
    float brightness;
    sf::Color color;

    for (auto &distance: _raysDistance) {
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
