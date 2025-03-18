/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#ifndef _ABSTRACT_VM_OPERAND_INTEGER_HPP_
#define _ABSTRACT_VM_OPERAND_INTEGER_HPP_

#include <memory>
#include <list>
#include <functional>

#include "AOperand.hpp"
#include "Arguments.hpp"

namespace AbstractVM
{
    class AOperandInteger : public AOperand {
        public:
            AOperandInteger(const std::string &value);
            ~AOperandInteger() = default;

            std::string toString() const override;

        protected:
            AOperandInteger() = delete;

            int _value;
    };

    class Int8 : public AOperandInteger {
        public:
            Int8(const std::string &value);
            ~Int8() = default;

            AbstractVM::IOperand::eOperandType getType() const override;

        private:
            Int8() = delete;
    };

    class Int16 : public AOperandInteger {
        public:
            Int16(const std::string &value);
            ~Int16() = default;

            AbstractVM::IOperand::eOperandType getType() const override;

        private:
            Int16() = delete;
    };

    class Int32 : public AOperandInteger {
        public:
            Int32(const std::string &value);
            ~Int32() = default;

            AbstractVM::IOperand::eOperandType getType() const override;

        private:
            Int32() = delete;
    };
}

#endif
