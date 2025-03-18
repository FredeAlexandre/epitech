/*
** EPITECH PROJECT, 2023
** Trantor
** File description:
** zappy
*/

#include "Trantor.hpp"

Trantor::Trantor(int playerId, Connector *connector, std::list<int> tileSize, SDL_Renderer *renderer, Team *team)
{
    _team = team;
    _playerId = playerId;
    _teamName = _teamName;
    _renderer = renderer;
    _isAlive = true;
    _moving = false;
    _broadcast = false;
    _connector = connector;
    _position.push_back(1);
    _position.push_front(0);
    _position.push_front(0);
    connector->getPlayerPosition(_playerId);
    _tileSize = tileSize;
    _pixelPosition.push_front(((1920 - 750) / 2) + _position.front() * _tileSize.front());
    int tempPos = _position.front();
    _position.pop_front();
    _pixelPosition.push_back(((1080 - 750) / 2) + _position.front() * _tileSize.back());
    _position.push_front(tempPos);
    _spriteSize = 64;
    _lastPosition.assign( _position.begin(), _position.end() );
    _lastPixelPosition.assign( _pixelPosition.begin(), _pixelPosition.end() );
    _animator = new Animator(renderer, _spriteSize, _spriteSize, "gui/src/sprites/TrantorAnimation.bmp", _team->getColor());
    _animator->setAnimationLine(2, 1, false);
    SDL_Surface* megaphone = SDL_LoadBMP("gui/src/sprites/Megaphone.bmp");
    if (!megaphone) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    _megaphone = SDL_CreateTextureFromSurface(renderer, megaphone);
    SDL_FreeSurface(megaphone);
}

Trantor::~Trantor()
{
    if (_megaphone)
        SDL_DestroyTexture(_megaphone);
}

void Trantor::setPlayerPosition(std::list<int> position)
{
    _position.assign(position.begin(), position.end());
}

void Trantor::update()
{
    if (_isAlive) {
        if (!_moving) {
            checkPosition();
        } else {
            move();
        }
        if (_broadcast) broadcast();
    }
    _animator->updateFrame();
    _animator->render(_lastPixelPosition.front(), _lastPixelPosition.back(), _tileSize.front(), _tileSize.back());
}

void Trantor::checkPosition()
{
    _connector->getPlayerPosition(_playerId);
    if (_position.front() != _lastPosition.front()) _moving = true;
    _pixelPosition.push_front(((1920 - 750) / 2) + _position.front() * _tileSize.front());
    int tempPos = _position.front();
    _position.pop_front();
    int tempLastPos = _lastPosition.front();
    _lastPosition.pop_front();
    _pixelPosition.push_back(((1080 - 750) / 2) + _position.front() * _tileSize.back());
    if (_position.front() != _lastPosition.front() && _moving) {
        _lastPixelPosition.front() = _pixelPosition.front();
        _lastPixelPosition.back() = _pixelPosition.back();
        _moving = false;
    } else if (_position.front() != _lastPosition.front()) _moving = true;
    _position.push_front(tempPos);
    _lastPosition.push_front(tempLastPos);
    if (_moving) {
        isMoving();
    } else if (_position.back() != _lastPosition.back()) {
        turn(_position.back());
    }
    _lastPosition.assign(_position.begin(), _position.end());
}

void Trantor::turn(int orientation)
{
    if (orientation == 1) {
        _animator->setAnimationLine(4, 1, false);
    }
    if (orientation == 2) {
        _animator->setAnimationLine(7, 1, false);
    }
    if (orientation == 3) {
        _animator->setAnimationLine(6, 1, false);
    }
    if (orientation == 4) {
        _animator->setAnimationLine(5, 1, false);
    }
}

void Trantor::isDead()
{
    _broadcast = false;
    _animator->setAnimationLine(20, 6, false);
    _isAlive = false;
}

void Trantor::broadcast()
{
    _broadcast = true;
    SDL_Rect megaphone = {_lastPixelPosition.front() + _tileSize.front() / 6, _lastPixelPosition.back() - _tileSize.back() / 2, _tileSize.front() * 2 / 3, _tileSize.back() * 2 / 3};
    SDL_RenderCopy(_renderer, _megaphone, NULL, &megaphone);
}

void Trantor::isMoving()
{
    if (_position.back() == 1) {
        _animator->setAnimationLine(8, 7, true);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(11, 7, true);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(10, 7, true);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(9, 7, true);
    }
}

void Trantor::move()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _lastPixelPosition.back() = _lastPixelPosition.back() - (_tileSize.back() / 70);
        if (_lastPixelPosition.back() <= _pixelPosition.back()) {
            _moving = false;
            _animator->setAnimationLine(0, 1, false);
            _lastPixelPosition.back() = _pixelPosition.back();
        }
    }
    if (_position.back() == 2) {
        _lastPixelPosition.front() = _lastPixelPosition.front() + (_tileSize.front() / 70);
        if (_lastPixelPosition.front() >= _pixelPosition.front()) {
            _moving = false;
            _animator->setAnimationLine(3, 1, false);
            _lastPixelPosition.front() = _pixelPosition.front();
        }
    }
    if (_position.back() == 3) {
        _lastPixelPosition.back() = _lastPixelPosition.back() + (_tileSize.back() / 70);
        if (_lastPixelPosition.back() >= _pixelPosition.back()) {
            _moving = false;
            _animator->setAnimationLine(2, 1, false);
            _lastPixelPosition.back() = _pixelPosition.back();
        }
    }
    if (_position.back() == 4) {
        _lastPixelPosition.front() = _lastPixelPosition.front() - (_tileSize.front() / 70);
        if (_lastPixelPosition.front() <= _pixelPosition.front()) {
            _moving = false;
            _animator->setAnimationLine(1, 1, false);
            _lastPixelPosition.front() = _pixelPosition.front();
        }
    }
}

void Trantor::isIncantated()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _animator->setAnimationLine(0, 7, true);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(3, 7, true);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(2, 7, true);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(1, 7, true);
    }
}

void Trantor::endIncantated()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _animator->setAnimationLine(4, 1, false);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(7, 1, false);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(6, 1, false);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(5, 1, false);
    }
}

void Trantor::dropRessource()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _animator->setAnimationLine(4, 8, false);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(7, 8, false);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(6, 8, false);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(5, 8, false);
    }
}

void Trantor::collectRessource()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _animator->setAnimationLine(4, 8, false);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(7, 8, false);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(6, 8, false);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(5, 8, false);
    }
}

void Trantor::layingEgg()
{
    _broadcast = false;
    if (_position.back() == 1) {
        _animator->setAnimationLine(4, 1, false);
    }
    if (_position.back() == 2) {
        _animator->setAnimationLine(7, 1, false);
    }
    if (_position.back() == 3) {
        _animator->setAnimationLine(6, 1, false);
    }
    if (_position.back() == 4) {
        _animator->setAnimationLine(5, 1, false);
    }
}

int Trantor::getIndex()
{
    return _playerId;
}

std::string Trantor::getTeamName()
{
    return _teamName;
}