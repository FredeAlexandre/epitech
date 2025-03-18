/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#ifndef _ABSTRACT_VM_OPERAND_DECIMAL_HPP_
#define _ABSTRACT_VM_OPERAND_DECIMAL_HPP_

#include <memory>
#include <list>
#include <functional>

#include "AOperand.hpp"

namespace AbstractVM
{
    class AOperandDecimal : public AOperand {
        public:
            AOperandDecimal(const std::string &value);
            ~AOperandDecimal() = default;

            std::string toString() const override;

        protected:
            AOperandDecimal() = delete;

            double _value;
            int _precision = 0;
    };

    class Float : public AOperandDecimal {
        public:
            Float(const std::string &value);
            ~Float() = default;

            AbstractVM::IOperand::eOperandType getType() const override;

        private:
            Float() = delete;
    };

    class Double : public AOperandDecimal {
        public:
            Double(const std::string &value);
            ~Double() = default;

            AbstractVM::IOperand::eOperandType getType() const override;

        private:
            Double() = delete;
    };
}

#endif
