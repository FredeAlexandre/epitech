/*
** EPITECH PROJECT, 2023
** SnakePart
** File description:
** arcade
*/

#ifndef _SNAKEENTITY_
#define _SNAKEENTITY_

#include "SnakeParts.hpp"

class SnakeEntity : public arcade::ecs::AEntity {
    public:
        SnakeEntity();
        ~SnakeEntity();
        void checkCollision();
        void move();
        int checkEatApple(int coordAppleX, int coordAppleY, std::list<std::shared_ptr<arcade::ecs::IEntity>> &entities);
        void checkDirection();
        inline std::string getId(void) const override { return "snake"; };
        bool isAlive();
        std::list<std::shared_ptr<SnakeParts>> &getEntities();
        int getScore();
        bool spacePress();
    protected:
        int _direction;
        bool _isAlive;
        std::list<std::shared_ptr<SnakeParts>> _Parts;
        std::shared_ptr<arcade::components::GetInputsComponent> inputsComponent;
        int taille;
        bool _spacePress = false;
};

#endif /* !_SNAKEPART_ */
