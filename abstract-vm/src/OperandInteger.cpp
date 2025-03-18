/*
** EPITECH PROJECT, 2022
** Operand.hpp
** File description:
** All operands possible
*/

#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

#include "OperandInteger.hpp"

AbstractVM::AOperandInteger::AOperandInteger(const std::string& value) {
    size_t next;
    _value = std::stoi(value, &next);
    if (next != value.size()) throw AbstractVM::IOperand::InvalidValue(value, "integer");
}

std::string AbstractVM::AOperandInteger::toString() const
{
    return std::to_string(_value);
}

AbstractVM::Int8::Int8(const std::string& value): AOperandInteger(value) {
    if (_value < -128 || _value > 127) throw AbstractVM::IOperand::InvalidValue(value, "int8");
}

AbstractVM::IOperand::eOperandType AbstractVM::Int8::getType() const
{
    return AbstractVM::IOperand::eOperandType::Int8;
}

AbstractVM::Int16::Int16(const std::string& value): AOperandInteger(value) {
    if (_value < -32768 || _value > 32767) throw AbstractVM::IOperand::InvalidValue(value, "int16");
}

AbstractVM::IOperand::eOperandType AbstractVM::Int16::getType() const
{
    return AbstractVM::IOperand::eOperandType::Int16;
}

AbstractVM::Int32::Int32(const std::string& value): AOperandInteger(value) {}

AbstractVM::IOperand::eOperandType AbstractVM::Int32::getType() const
{
    return AbstractVM::IOperand::eOperandType::Int32;
}
