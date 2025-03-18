/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#ifndef _ABSTRACT_VM_AOPERAND_HPP_
#define _ABSTRACT_VM_AOPERAND_HPP_

#include <memory>
#include <list>
#include <functional>

#include "IOperand.hpp"
#include "Arguments.hpp"

namespace AbstractVM
{
    class AOperand : public AbstractVM::IOperand {
        public:
            AbstractVM::IOperand* operator+(const AbstractVM::IOperand &rhs) const override;
            AbstractVM::IOperand* operator-(const AbstractVM::IOperand &rhs) const override;
            AbstractVM::IOperand* operator*(const AbstractVM::IOperand &rhs) const override;
            AbstractVM::IOperand* operator/(const AbstractVM::IOperand &rhs) const override;
            AbstractVM::IOperand* operator%(const AbstractVM::IOperand &rhs) const override;

        protected:
            std::string doubleToString(double value, int precision) const;
            std::string doubleToString(double value, bool isFloat) const;
    };
}

#endif
