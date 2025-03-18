/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-arcade-alexandre.frede
** File description:
** WallEntity
*/

#ifndef WALLEntity_HPP_
#define WALLEntity_HPP_

#include "arcade.hpp"
#include <iostream>

class WallEntity : public arcade::ecs::AEntity {
    public:
        WallEntity(float x, float y);
        ~WallEntity();
        inline std::string getId(void) const override { return Id; };
    protected:
    private:
        std::string Id;
};

#endif /* !WALLENTITY_HPP_ */
