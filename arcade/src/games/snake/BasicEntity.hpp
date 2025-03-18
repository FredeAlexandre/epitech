/*
** EPITECH PROJECT, 2023
** basicEntity
** File description:
** arcade
*/

#ifndef _BASIC_
#define _BASIC_
#include "arcade.hpp"

class BasicEntity : public arcade::ecs::AEntity {
    public:
        BasicEntity(std::string str);
        ~BasicEntity() = default;
        inline std::string getId(void) const override { return Id; };

    protected:
    std::string Id;
    private:
};

#endif /* !_BASIC_ */
