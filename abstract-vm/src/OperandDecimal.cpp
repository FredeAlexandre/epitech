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

#include "OperandDecimal.hpp"

AbstractVM::AOperandDecimal::AOperandDecimal(const std::string& value) {
    size_t next;
    _value = std::stod(value, &next);
    if (next != value.size()) throw AbstractVM::IOperand::InvalidValue(value, "decimal");
    if (value.find('.') == std::string::npos) return;
    bool start_count = false;
    for (auto c : value) {
        if (start_count) _precision++;
        if (c == '.') start_count = true;
    }
}

std::string AbstractVM::AOperandDecimal::toString() const
{
    if (getType() == AbstractVM::IOperand::eOperandType::Float) {
        return doubleToString(_value, _precision > 7 ? 7 : _precision);
    }
    if (getType() == AbstractVM::IOperand::eOperandType::Double) {
        return doubleToString(_value, _precision > 15 ? 15 : _precision);
    }
    throw AbstractVM::IOperand::InvalidType();
}

AbstractVM::Float::Float(const std::string& value): AOperandDecimal(value) {
    if (_value < -std::numeric_limits<float>::max() || _value > std::numeric_limits<float>::max()) throw InvalidValue(value, "float");
}

AbstractVM::IOperand::eOperandType AbstractVM::Float::getType() const
{
    return AbstractVM::IOperand::eOperandType::Float;
}

AbstractVM::Double::Double(const std::string& value): AOperandDecimal(value) {}

AbstractVM::IOperand::eOperandType AbstractVM::Double::getType() const
{
    return AbstractVM::IOperand::eOperandType::Double;
}
