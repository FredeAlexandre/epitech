/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "arcade.hpp"
#include "SFML/Graphics.hpp"
#include "SFML.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics/Color.hpp"
#include <iostream>

using KeyToInput = std::map<sf::Keyboard::Key, arcade::enums::Input>;

const KeyToInput getKeyToInput = {
    {sf::Keyboard::A, arcade::enums::A},
    {sf::Keyboard::B, arcade::enums::B},
    {sf::Keyboard::C, arcade::enums::C},
    {sf::Keyboard::D, arcade::enums::D},
    {sf::Keyboard::E, arcade::enums::E},
    {sf::Keyboard::F, arcade::enums::F},
    {sf::Keyboard::G, arcade::enums::G},
    {sf::Keyboard::H, arcade::enums::H},
    {sf::Keyboard::I, arcade::enums::I},
    {sf::Keyboard::J, arcade::enums::J},
    {sf::Keyboard::K, arcade::enums::K},
    {sf::Keyboard::L, arcade::enums::L},
    {sf::Keyboard::M, arcade::enums::M},
    {sf::Keyboard::N, arcade::enums::N},
    {sf::Keyboard::O, arcade::enums::O},
    {sf::Keyboard::P, arcade::enums::P},
    {sf::Keyboard::Q, arcade::enums::Q},
    {sf::Keyboard::R, arcade::enums::R},
    {sf::Keyboard::S, arcade::enums::S},
    {sf::Keyboard::T, arcade::enums::T},
    {sf::Keyboard::U, arcade::enums::U},
    {sf::Keyboard::V, arcade::enums::V},
    {sf::Keyboard::W, arcade::enums::W},
    {sf::Keyboard::X, arcade::enums::X},
    {sf::Keyboard::Y, arcade::enums::Y},
    {sf::Keyboard::Z, arcade::enums::Z},
    {sf::Keyboard::Num0, arcade::enums::Num0},
    {sf::Keyboard::Num1, arcade::enums::Num1},
    {sf::Keyboard::Num2, arcade::enums::Num2},
    {sf::Keyboard::Num3, arcade::enums::Num3},
    {sf::Keyboard::Num4, arcade::enums::Num4},
    {sf::Keyboard::Num5, arcade::enums::Num5},
    {sf::Keyboard::Num6, arcade::enums::Num6},
    {sf::Keyboard::Num7, arcade::enums::Num7},
    {sf::Keyboard::Num8, arcade::enums::Num8},
    {sf::Keyboard::Num9, arcade::enums::Num9},
    {sf::Keyboard::Escape, arcade::enums::Escape},
    {sf::Keyboard::LControl, arcade::enums::LControl},
    {sf::Keyboard::LShift, arcade::enums::LShift},
    {sf::Keyboard::LAlt, arcade::enums::LAlt},
    {sf::Keyboard::RControl, arcade::enums::RControl},
    {sf::Keyboard::RShift, arcade::enums::RShift},
    {sf::Keyboard::RAlt, arcade::enums::RAlt},
    {sf::Keyboard::Menu, arcade::enums::Menu},
    {sf::Keyboard::LBracket, arcade::enums::LBracket},
    {sf::Keyboard::RBracket, arcade::enums::RBracket},
    {sf::Keyboard::SemiColon, arcade::enums::SemiColon},
    {sf::Keyboard::Comma, arcade::enums::Comma},
    {sf::Keyboard::Period, arcade::enums::Period},
    {sf::Keyboard::Quote, arcade::enums::Quote},
    {sf::Keyboard::Slash, arcade::enums::Slash},
    {sf::Keyboard::BackSlash, arcade::enums::BackSlash},
    {sf::Keyboard::Tilde, arcade::enums::Tilde},
    {sf::Keyboard::Equal, arcade::enums::Equal},
    {sf::Keyboard::Dash, arcade::enums::Dash},
    {sf::Keyboard::Space, arcade::enums::Space},
    {sf::Keyboard::Return, arcade::enums::Return},
    {sf::Keyboard::BackSpace, arcade::enums::BackSpace},
    {sf::Keyboard::Tab, arcade::enums::Tab},
    {sf::Keyboard::PageUp, arcade::enums::PageUp},
    {sf::Keyboard::PageDown, arcade::enums::PageDown},
    {sf::Keyboard::End, arcade::enums::End},
    {sf::Keyboard::Home, arcade::enums::Home},
    {sf::Keyboard::Insert, arcade::enums::Insert},
    {sf::Keyboard::Delete, arcade::enums::Delete},
    {sf::Keyboard::Add, arcade::enums::Add},
    {sf::Keyboard::Subtract, arcade::enums::Subtract},
    {sf::Keyboard::Multiply, arcade::enums::Multiply},
    {sf::Keyboard::Divide, arcade::enums::Divide},
    {sf::Keyboard::Left, arcade::enums::Left},
    {sf::Keyboard::Right, arcade::enums::Right},
    {sf::Keyboard::Up, arcade::enums::Up},
    {sf::Keyboard::Down, arcade::enums::Down},
    {sf::Keyboard::Numpad0, arcade::enums::Numpad0},
    {sf::Keyboard::Numpad1, arcade::enums::Numpad1},
    {sf::Keyboard::Numpad2, arcade::enums::Numpad2},
    {sf::Keyboard::Numpad3, arcade::enums::Numpad3},
    {sf::Keyboard::Numpad4, arcade::enums::Numpad4},
    {sf::Keyboard::Numpad5, arcade::enums::Numpad5},
    {sf::Keyboard::Numpad6, arcade::enums::Numpad6},
    {sf::Keyboard::Numpad7, arcade::enums::Numpad7},
    {sf::Keyboard::Numpad8, arcade::enums::Numpad8},
    {sf::Keyboard::Numpad9, arcade::enums::Numpad9},
    {sf::Keyboard::F1, arcade::enums::F1},
    {sf::Keyboard::F2, arcade::enums::F2},
    {sf::Keyboard::F3, arcade::enums::F3},
    {sf::Keyboard::F4, arcade::enums::F4},
    {sf::Keyboard::F5, arcade::enums::F5},
    {sf::Keyboard::F6, arcade::enums::F6},
    {sf::Keyboard::F7, arcade::enums::F7},
    {sf::Keyboard::F8, arcade::enums::F8},
    {sf::Keyboard::F9, arcade::enums::F9},
    {sf::Keyboard::F10, arcade::enums::F10},
    {sf::Keyboard::F11, arcade::enums::F11},
    {sf::Keyboard::F12, arcade::enums::F12},
    {sf::Keyboard::F13, arcade::enums::F13},
    {sf::Keyboard::F14, arcade::enums::F14},
    {sf::Keyboard::F15, arcade::enums::F15},
    {sf::Keyboard::Pause, arcade::enums::Pause},
    {sf::Keyboard::KeyCount, arcade::enums::KeyCount}
};

class SFML : public arcade::IGraphic {
    public:
        SFML();
        ~SFML();
        void init(arcade::GraphicInit value);
        void update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void DrawAll(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void DrawSprite(const std::shared_ptr<arcade::components::SpriteComponent> SpriteComp, const std::shared_ptr<arcade::components::PositionComponent> PosComp, const std::shared_ptr<arcade::components::SizeComponent> SizeComp, const std::string path);
        void giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &inputs);
        void freeLoadedTextures();
        void DrawText(std::shared_ptr<arcade::components::TextComponent> TextComp);
        void catchExit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        std::map<std::string, std::shared_ptr<sf::Texture>> _loadedTextures;
};

#endif /* !SFML_HPP_ */
