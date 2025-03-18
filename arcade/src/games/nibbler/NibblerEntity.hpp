/*
** EPITECH PROJECT, 2023
** NibblerPart
** File description:
** arcade
*/

#ifndef _NibblerEntity_
#define _NibblerEntity_

#include "NibblerParts.hpp"
#include "iostream"

class NibblerEntity : public arcade::ecs::AEntity {
    public:
        NibblerEntity();
        ~NibblerEntity();
        void checkCollision();
        void move();
        int checkEatApple(int coordAppleX, int coordAppleY, std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void checkDirection();
        bool checkSurroundings(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        inline std::string getId(void) const override { return "Nibbler"; };
        bool isAlive();
        std::list<std::shared_ptr<NibblerParts>> &getEntities();
        int getScore();
        bool spacePress();
        std::list<std::shared_ptr<NibblerParts>> getParts();
        int AddPart(std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
    protected:
        int _direction;
        bool _isAlive;
        std::list<std::shared_ptr<NibblerParts>> _Parts;
        std::shared_ptr<arcade::components::GetInputsComponent> inputsComponent;
        int taille;
        bool _spacePress = false;
};

#endif /* !_NibblerPART_ */
