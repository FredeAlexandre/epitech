/*
** EPITECH PROJECT, 2023
** sdl2arcade
** File description:
** _SDL2_
*/

#ifndef _SDL2_
#define _SDL2_

#include "arcade.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>
#define FONT_SOURCE "./Font/"

using KeyToInput = std::map<SDL_Keycode, arcade::enums::Input>;

const KeyToInput getKeyToInput = {
    {SDLK_a, arcade::enums::A},
    {SDLK_b, arcade::enums::B},
    {SDLK_c, arcade::enums::C},
    {SDLK_d, arcade::enums::D},
    {SDLK_e, arcade::enums::E},
    {SDLK_f, arcade::enums::F},
    {SDLK_g, arcade::enums::G},
    {SDLK_h, arcade::enums::H},
    {SDLK_i, arcade::enums::I},
    {SDLK_j, arcade::enums::J},
    {SDLK_k, arcade::enums::K},
    {SDLK_l, arcade::enums::L},
    {SDLK_m, arcade::enums::M},
    {SDLK_n, arcade::enums::N},
    {SDLK_o, arcade::enums::O},
    {SDLK_p, arcade::enums::P},
    {SDLK_q, arcade::enums::Q},
    {SDLK_r, arcade::enums::R},
    {SDLK_s, arcade::enums::S},
    {SDLK_t, arcade::enums::T},
    {SDLK_u, arcade::enums::U},
    {SDLK_v, arcade::enums::V},
    {SDLK_w, arcade::enums::W},
    {SDLK_x, arcade::enums::X},
    {SDLK_y, arcade::enums::Y},
    {SDLK_z, arcade::enums::Z},
    {SDLK_0, arcade::enums::Num0},
    {SDLK_1, arcade::enums::Num1},
    {SDLK_2, arcade::enums::Num2},
    {SDLK_3, arcade::enums::Num3},
    {SDLK_4, arcade::enums::Num4},
    {SDLK_5, arcade::enums::Num5},
    {SDLK_6, arcade::enums::Num6},
    {SDLK_7, arcade::enums::Num7},
    {SDLK_8, arcade::enums::Num8},
    {SDLK_9, arcade::enums::Num9},
    {SDLK_ESCAPE, arcade::enums::Escape},
    {SDLK_LCTRL, arcade::enums::LControl},
    {SDLK_LSHIFT, arcade::enums::LShift},
    {SDLK_LALT, arcade::enums::LAlt},
    {SDLK_LGUI, arcade::enums::LSystem},
    {SDLK_RCTRL, arcade::enums::RControl},
    {SDLK_RSHIFT, arcade::enums::RShift},
    {SDLK_RALT, arcade::enums::RAlt},
    {SDLK_RGUI, arcade::enums::RSystem},
    {SDLK_MENU, arcade::enums::Menu},
    {SDLK_LEFTBRACKET, arcade::enums::LBracket},
    {SDLK_RIGHTBRACKET, arcade::enums::RBracket},
    {SDLK_SEMICOLON, arcade::enums::SemiColon},
    {SDLK_COMMA, arcade::enums::Comma},
    {SDLK_PERIOD, arcade::enums::Period},
    {SDLK_QUOTE, arcade::enums::Quote},
    {SDLK_SLASH, arcade::enums::Slash},
    {SDLK_BACKSLASH, arcade::enums::BackSlash},
    {SDLK_EQUALS, arcade::enums::Equal},
    {SDLK_MINUS, arcade::enums::Dash},
    {SDLK_SPACE, arcade::enums::Space},
    {SDLK_RETURN, arcade::enums::Return},
    {SDLK_BACKSPACE, arcade::enums::BackSpace},
    {SDLK_TAB, arcade::enums::Tab},
    {SDLK_PAGEUP, arcade::enums::PageUp},
    {SDLK_PAGEDOWN, arcade::enums::PageDown},
    {SDLK_END, arcade::enums::End},
    {SDLK_HOME, arcade::enums::Home},
    {SDLK_INSERT, arcade::enums::Insert},
    {SDLK_DELETE, arcade::enums::Delete},
    {SDLK_KP_PLUS, arcade::enums::Add},
    {SDLK_KP_MINUS, arcade::enums::Subtract},
    {SDLK_KP_MULTIPLY, arcade::enums::Multiply},
    {SDLK_KP_DIVIDE, arcade::enums::Divide},
    {SDLK_LEFT, arcade::enums::Left},
    {SDLK_RIGHT, arcade::enums::Right},
    {SDLK_UP, arcade::enums::Up},
    {SDLK_DOWN, arcade::enums::Down},
    {SDLK_KP_0, arcade::enums::Numpad0},
    {SDLK_KP_1, arcade::enums::Numpad1},
    {SDLK_KP_2, arcade::enums::Numpad2},
    {SDLK_KP_3, arcade::enums::Numpad3},
    {SDLK_KP_4, arcade::enums::Numpad4},
    {SDLK_KP_5, arcade::enums::Numpad5},
    {SDLK_KP_6, arcade::enums::Numpad6},
    {SDLK_KP_7, arcade::enums::Numpad7},
    {SDLK_KP_8, arcade::enums::Numpad8},
    {SDLK_KP_9, arcade::enums::Numpad9},
    {SDLK_F1, arcade::enums::F1},
    {SDLK_F2, arcade::enums::F2},
    {SDLK_F3, arcade::enums::F3},
    {SDLK_F4, arcade::enums::F4},
    {SDLK_F5, arcade::enums::F5},
    {SDLK_F6, arcade::enums::F6},
    {SDLK_F7, arcade::enums::F7},
    {SDLK_F8, arcade::enums::F8},
    {SDLK_F9, arcade::enums::F9},
    {SDLK_F10, arcade::enums::F10},
    {SDLK_F11, arcade::enums::F11},
    {SDLK_F12, arcade::enums::F12},
    {SDLK_F13, arcade::enums::F13},
    {SDLK_F14, arcade::enums::F14},
    {SDLK_F15, arcade::enums::F15},
    {SDLK_PAUSE, arcade::enums::Pause},
};

class SDL2 : public arcade::IGraphic {
    public:
        SDL2();
        ~SDL2();
        void init(arcade::GraphicInit value);
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void DrawSprite(std::shared_ptr<arcade::ecs::IEntity> entity);
        arcade::enums::Input convertInput(SDL_Event event);
        void giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &keys);
        void exit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
    protected:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::map<std::string, SDL_Texture *> _TextureMap;
        arcade::GraphicInit _value = {0, 0};
};
#endif /* !_SDL2_ */
