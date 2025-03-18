/*
** EPITECH PROJECT, 2023
** Animator
** File description:
** zappy
*/

#include "Animator.hpp"

Animator::Animator(SDL_Renderer *renderer, int widthSprite, int heightSprite, std::string filepath, SDL_Color color)
{
    _renderer = renderer;
    _widthSprite = widthSprite;
    _heightSprite = heightSprite;
    _spriteSheet = nullptr;
    _boucle = true;
    _currentFrame = 0;
    _frameCount = 1;
    SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
    if (!surface) {
        std::cerr << "Failed to load sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }
    _spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!_spriteSheet) {
        std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetTextureColorMod(_spriteSheet, color.r, color.g, color.b);
    _lastTime = SDL_GetTicks();
}

Animator::~Animator() {
    if (_spriteSheet) {
        SDL_DestroyTexture(_spriteSheet);
    }
}

void Animator::updateFrame()
{
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - _lastTime >= 1000 / 30) {
        if (!_boucle && (_currentFrame + 1) >= _frameCount) return;
        _currentFrame = (_currentFrame + 1) % _frameCount;
        _lastTime = currentTime;
    }
}

void Animator::render(int x, int y, int width, int height)
{
    SDL_Rect srcRect = {_currentFrame * _widthSprite, _animationLine * _heightSprite, _widthSprite, _heightSprite};
    SDL_Rect destRect = {x, y, width, height};

    SDL_RenderCopy(_renderer, _spriteSheet, &srcRect, &destRect);
}

void Animator::setAnimationLine(int animationLine, int frameCount, bool boucle)
{
    _animationLine = animationLine;
    _boucle = boucle;
    _frameCount = frameCount;
    _currentFrame = 0;
}