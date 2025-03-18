/*
** EPITECH PROJECT, 2023
** animator
** File description:
** zappy
*/

#ifndef _ANIMATOR_
#define _ANIMATOR_
    #include <SDL2/SDL.h>
    #include <iostream>

class Animator {
    public:
        Animator(SDL_Renderer* renderer, int widthSprite, int heightSprite, std::string filepath, SDL_Color color);
        ~Animator();

        void updateFrame();
        void render(int x, int y, int width, int height);
        void setAnimationLine(int animationLine, int frameCount, bool boucle);

    private:
        Uint32 _lastTime;
        SDL_Texture* _spriteSheet;
        SDL_Renderer* _renderer;
        int _currentFrame;
        int _frameCount;
        int _widthSprite;
        int _heightSprite;
        int _animationLine;
        bool _boucle;
};

#endif /* !_ANIMATOR_ */
