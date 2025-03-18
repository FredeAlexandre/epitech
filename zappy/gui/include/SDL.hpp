/*
** EPITECH PROJECT, 2023
** SDL
** File description:
** A class to handle SDL
*/

#include <SDL2/SDL.h>

#include <string>

#ifndef _ZAPPY_GUI_SDL_
#define _ZAPPY_GUI_SDL_

namespace zappy {
    class SDL {
        public:
            SDL(const std::string &title, int width, int height);
            ~SDL();

            void setBackgroundColor(Uint8 r, Uint8 g, Uint8 b);

        protected:
            SDL_Window *Window;
            SDL_Renderer *BackgroundRenderer;
    };
}

#endif /* !_ZAPPY_GUI_SDL_ */
