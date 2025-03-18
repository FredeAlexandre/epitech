/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#ifndef _ABSTRACT_VM_OPERAND_FACTORY_HPP_
#define _ABSTRACT_VM_OPERAND_FACTORY_HPP_

#include <memory>
#include <list>
#include <functional>

#include "IOperand.hpp"

namespace AbstractVM {
    class OperandFactory {
        public:
            OperandFactory() = default;
            OperandFactory(OperandFactory const&) = delete;
            void operator=(OperandFactory const&) = delete;
            ~OperandFactory();

            static AbstractVM::IOperand* createOperand(AbstractVM::IOperand::eOperandType type, const std::string& value);
            static AbstractVM::IOperand* createOperand(const std::string& string);
            static AbstractVM::IOperand* createOperand(const AbstractVM::IOperand& operand);

            static bool isInt(AbstractVM::IOperand::eOperandType type);
            static bool isDecimal(AbstractVM::IOperand::eOperandType type);
            static AbstractVM::IOperand::eOperandType getWinningType(AbstractVM::IOperand::eOperandType type1, AbstractVM::IOperand::eOperandType type2);
            static AbstractVM::IOperand::eOperandType strToType(const std::string &type);
            static std::string typeToStr(AbstractVM::IOperand::eOperandType type);
            static std::string serialize(const AbstractVM::IOperand& operand);

        private:
            AbstractVM::IOperand* createInt8(const std::string& value);
            AbstractVM::IOperand* createInt16(const std::string& value);
            AbstractVM::IOperand* createInt32(const std::string& value);
            AbstractVM::IOperand* createFloat(const std::string& value);
            AbstractVM::IOperand* createDouble(const std::string& value);

            AbstractVM::IOperand* addOperand(AbstractVM::IOperand* operand);

            std::list<AbstractVM::IOperand*> _operands;

            static std::unique_ptr<OperandFactory> _instance;
            static std::function<AbstractVM::IOperand*(OperandFactory*, const std::string& value)> _create[AbstractVM::IOperand::eOperandType::Max];
            static std::string _type[AbstractVM::IOperand::eOperandType::Max];
    };
}


#endif
