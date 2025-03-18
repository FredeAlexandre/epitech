/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#ifndef _ABSTRACT_VM_IOPERAND_HPP_
#define _ABSTRACT_VM_IOPERAND_HPP_

#include <memory>
#include <list>
#include <functional>

#include "Arguments.hpp"

namespace AbstractVM
{
    class IOperand {
        public:
            virtual ~IOperand() = default;

            enum eOperandType {
                Min = 0,
                Int8 = 0,
                Int16,
                Int32,
                Float,
                Double,
                Max,
                Unknown
            };

            virtual std::string toString() const = 0;
            virtual eOperandType getType() const = 0;

            virtual IOperand* operator+(const IOperand &rhs) const = 0;
            virtual IOperand* operator-(const IOperand &rhs) const = 0;
            virtual IOperand* operator*(const IOperand &rhs) const = 0;
            virtual IOperand* operator/(const IOperand &rhs) const = 0;
            virtual IOperand* operator%(const IOperand &rhs) const = 0;

            class InvalidType : public std::runtime_error {
                public:
                    InvalidType() : std::runtime_error("Ceation of an unknow operand type") {}
            };

            class InvalidOperand : public std::runtime_error {
                public:
                    InvalidOperand(const std::string &gived) : std::runtime_error("Invalid operand: " + gived) {}
            };

            class InvalidValue : public std::runtime_error {
                public:
                    InvalidValue(const std::string &value, const std::string &type) : std::runtime_error("The value: " + value + " can't be an " + type) {}
            };

            class DivisionByZero : public std::runtime_error {
                public:
                    DivisionByZero() : std::runtime_error("Division by zero") {}
            };

            class Overflow : public std::runtime_error {
                public:
                    Overflow() : std::runtime_error("Overflow") {}
            };

            class Underflow : public std::runtime_error {
                public:
                    Underflow() : std::runtime_error("Underflow") {}
            };
    };
}

#endif
