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

#include "OperandFactory.hpp"

#include "OperandInteger.hpp"
#include "OperandDecimal.hpp"

bool AbstractVM::OperandFactory::isInt(AbstractVM::IOperand::eOperandType type)
{
    return type == AbstractVM::IOperand::Int8 || type == AbstractVM::IOperand::Int16 || type == AbstractVM::IOperand::Int32;
}

bool AbstractVM::OperandFactory::isDecimal(AbstractVM::IOperand::eOperandType type)
{
    return type == AbstractVM::IOperand::Float || type == AbstractVM::IOperand::Double;
}

AbstractVM::IOperand::eOperandType AbstractVM::OperandFactory::getWinningType(AbstractVM::IOperand::eOperandType type1, AbstractVM::IOperand::eOperandType type2)
{
    return type1 > type2 ? type1 : type2;
}

AbstractVM::OperandFactory::~OperandFactory()
{
    for (auto &operand : _operands) delete operand;
}

std::unique_ptr<AbstractVM::OperandFactory> AbstractVM::OperandFactory::_instance = nullptr;

std::function<AbstractVM::IOperand*(AbstractVM::OperandFactory*, const std::string& value)> AbstractVM::OperandFactory::_create[] = {
    &AbstractVM::OperandFactory::createInt8,
    &AbstractVM::OperandFactory::createInt16,
    &AbstractVM::OperandFactory::createInt32,
    &AbstractVM::OperandFactory::createFloat,
    &AbstractVM::OperandFactory::createDouble
};

std::string AbstractVM::OperandFactory::_type[] = {
    "int8",
    "int16",
    "int32",
    "float",
    "double"
};

AbstractVM::IOperand* AbstractVM::OperandFactory::createOperand(AbstractVM::IOperand::eOperandType type, const std::string& value)
{
    if (_instance == nullptr) _instance = std::make_unique<OperandFactory>();

    if (type > AbstractVM::IOperand::eOperandType::Max) throw AbstractVM::IOperand::InvalidType();
    if (type < AbstractVM::IOperand::eOperandType::Min) throw AbstractVM::IOperand::InvalidType();
    return _create[type](_instance.get(), value);
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createInt8(const std::string& value)
{
    return addOperand(new Int8(value));
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createInt16(const std::string& value)
{
    return addOperand(new Int16(value));
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createInt32(const std::string& value)
{
    return addOperand(new Int32(value));
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createFloat(const std::string& value)
{
    return addOperand(new Float(value));
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createDouble(const std::string& value)
{
    return addOperand(new Double(value));
}

AbstractVM::IOperand* AbstractVM::OperandFactory::addOperand(AbstractVM::IOperand* operand)
{
    _operands.push_back(operand);
    return operand;
}

AbstractVM::IOperand::eOperandType AbstractVM::OperandFactory::strToType(const std::string &type)
{
    if (type == "int8") return AbstractVM::IOperand::eOperandType::Int8;
    if (type == "int16") return AbstractVM::IOperand::eOperandType::Int16;
    if (type == "int32") return AbstractVM::IOperand::eOperandType::Int32;
    if (type == "float") return AbstractVM::IOperand::eOperandType::Float;
    if (type == "double") return AbstractVM::IOperand::eOperandType::Double;
    return AbstractVM::IOperand::eOperandType::Unknown;
}

std::string AbstractVM::OperandFactory::typeToStr(AbstractVM::IOperand::eOperandType type)
{
    return _type[type];
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createOperand(const std::string& string)
{
    size_t pos = string.find('(');
    if (pos == std::string::npos) throw AbstractVM::IOperand::InvalidOperand(string);
    std::string type = string.substr(0, pos);
    size_t end = string.find(')');
    if (end == std::string::npos) throw AbstractVM::IOperand::InvalidOperand(string);
    std::string value = string.substr(pos + 1, end - pos - 1);
    if (end != string.size() - 1) throw AbstractVM::IOperand::InvalidOperand(string);
    return createOperand(strToType(type), value);
}

AbstractVM::IOperand* AbstractVM::OperandFactory::createOperand(const AbstractVM::IOperand& operand)
{
    return createOperand(operand.getType(), operand.toString());
}

std::string AbstractVM::OperandFactory::serialize(const AbstractVM::IOperand &operand)
{
    return typeToStr(operand.getType()) + "(" + operand.toString() + ")";
}
