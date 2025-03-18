/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** entry
*/

#include "SFML.hpp"

extern "C" {
    arcade::IGraphic *getGraphic(void) {
        return new SFML();
    }
    void destroyGraphic(arcade::IGraphic *lib) {
        delete lib;
    }
};

SFML::SFML()
{
};

SFML::~SFML()
{

    if (LOGS)
        std::cout << "[SFML] Destroy" << std::endl;
    if (_window.isOpen())
        _window.close();
    freeLoadedTextures();
};

void SFML::init(arcade::GraphicInit value)
{
    if (LOGS)
        std::cout << "[SFML] Init" << std::endl;
    _window.create(sf::VideoMode(value.width, value.height), "SFML window", sf::Style::Default);
    _window.clear(sf::Color::Black);
    _window.display();
}

void SFML::DrawText(std::shared_ptr<arcade::components::TextComponent> TextComp)
{
    if (LOGS)
        std::cout << "[SFML] Drawing Text" << std::endl;
    sf::Font ArialFont;
    sf::Text myText;
    int horizontal = (_window.getSize().x / 3) * (TextComp.get()->horizontalPosition);
    if (LOGS)
        std::cout << TextComp.get()->horizontalPosition << std::endl;
    int vertical = (_window.getSize().y / 3) * (TextComp.get()->verticalPosition);
    if (LOGS)
        std::cout << TextComp.get()->verticalPosition << std::endl;

    if (ArialFont.loadFromFile("./Font/PoliceGame.TTF")) {
        myText.setFont(ArialFont);
        myText.setString(TextComp.get()->value);
        myText.setCharacterSize(50);
        myText.setFillColor(sf::Color::White);
        myText.setStyle(sf::Text::Bold);
        myText.setPosition(10 + horizontal, 10 + vertical);
        _window.draw(myText);
    }
}

void SFML::DrawSprite(const std::shared_ptr<arcade::components::SpriteComponent> SpriteComp, const std::shared_ptr<arcade::components::PositionComponent> PosComp, const std::shared_ptr<arcade::components::SizeComponent> SizeComp, const std::string path)
{
    if (LOGS)
        std::cout << "[SFML] Drawing Sprite" << std::endl;
    sf::Sprite sprite;
    sf::Texture texture;
    float x = PosComp.get()->x, y = PosComp.get()->y;
    float angle = (float)PosComp.get()->rotation;

    if (_loadedTextures[path] == nullptr) {
        if (LOGS)
            std::cout << "unloaded" << std::endl;
        if (!texture.loadFromFile(path)) {
            if (!texture.loadFromFile("./Sprites/Unloaded_sprite.png"))
                texture.loadFromFile("../../Sprites/Unloaded_sprite.png");
        } else {
            _loadedTextures[path] = std::make_shared<sf::Texture>(texture);
        }
        sprite.setTexture(texture);
    } else {
        sprite.setTexture(*_loadedTextures[path]);
    }
    sprite.setScale(SizeComp.get()->width / sprite.getGlobalBounds().width, SizeComp.get()->height / sprite.getGlobalBounds().height);
    if (angle != 0) {
        //sprite.setOrigin((sprite.getLocalBounds().height / 2), (sprite.getLocalBounds().width / 2));
        sprite.setPosition(x, y);
        //sprite.setRotation(angle);
    } else {
        sprite.setPosition(x, y);
    }
    _window.draw(sprite);
}

void SFML::DrawAll(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    if (LOGS)
        std::cout << "[SFML] Drawing Sprite and Text components of entities" << std::endl;
    for (auto it = entities.rbegin(); it != entities.rend(); ++it) {
        auto SpriteComp = Helper::getComponent<arcade::components::SpriteComponent>(*it->get());
        auto PosComp = Helper::getComponent<arcade::components::PositionComponent>(*it->get());
        auto SpriteSheet = Helper::getComponent<arcade::components::SpriteSheetComponent>(*it->get());
        auto SizeComp = Helper::getComponent<arcade::components::SizeComponent>(*it->get());
        if (SpriteComp && PosComp && SpriteSheet && SizeComp) {
            DrawSprite(SpriteComp, PosComp, SizeComp, SpriteSheet->source);
        }
        auto TextComp = Helper::getComponent<arcade::components::TextComponent>(*it->get());
        if (TextComp) {
            DrawText(TextComp);
        }
    }
    _window.display();
    if (LOGS)
        std::cout << "[SFML] EndFrame" << std::endl;
}

void SFML::update(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    if (!_window.isOpen()) return;

    std::list<arcade::enums::Input> inputs;

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            if (LOGS)
                std::cout << "[SFML] Close signal" << std::endl;
            catchExit(entities);
            return;
        } else if (_event.type == sf::Event::KeyPressed) {
            if (LOGS)
                std::cout << "[SFML] input signal" << std::endl;
            if (getKeyToInput.find(_event.key.code) != getKeyToInput.end())
                inputs.push_back(getKeyToInput.at(_event.key.code));
        }
    }

    giveInputs(entities, inputs);

    _window.clear(sf::Color::Black);
    DrawAll(entities);
}

void SFML::catchExit(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities)
{
    std::list<std::shared_ptr<arcade::ecs::IEntity>>::iterator it;
    std::shared_ptr<arcade::components::ExitComponent> ExitComp;

    for (it = entities.begin(); it != entities.end(); ++it) {
        ExitComp = Helper::getComponent<arcade::components::ExitComponent>(*it->get());
        if (ExitComp != nullptr) {
            ExitComp.get()->exit = true;
        }
    }
}

void SFML::giveInputs(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities, std::list<arcade::enums::Input> &inputs)
{
    for (auto entity : entities) {
        auto InputComp = Helper::getComponent<arcade::components::GetInputsComponent>(*entity.get());
        if (InputComp != nullptr) {
            InputComp.get()->inputs = inputs;
        }
    }
}

void SFML::freeLoadedTextures()
{
    _loadedTextures.clear();
}
