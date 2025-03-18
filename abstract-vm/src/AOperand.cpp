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
#include "AOperand.hpp"

AbstractVM::IOperand* AbstractVM::AOperand::operator+(const AbstractVM::IOperand &rhs) const
{
    auto type = OperandFactory::getWinningType(this->getType(), rhs.getType());
    if (AbstractVM::OperandFactory::isDecimal(type)) {
        double a = std::stod(this->toString());
        double b = std::stod(rhs.toString());
        double result = a + b;
        if (b > 0 && result < a) throw AbstractVM::IOperand::Overflow();
        if (b < 0 && result > a) throw AbstractVM::IOperand::Underflow();
        return AbstractVM::OperandFactory::createOperand(type, doubleToString(result, getType() == AbstractVM::IOperand::eOperandType::Float));
    }
    if (AbstractVM::OperandFactory::isInt(type)) {
        int a = std::stoi(this->toString());
        int b = std::stoi(rhs.toString());
        int result = a + b;
        if (b > 0 && result < a) throw AbstractVM::IOperand::Overflow();
        if (b < 0 && result > a) throw AbstractVM::IOperand::Underflow();
        return AbstractVM::OperandFactory::createOperand(type, std::to_string(result));
    }
    throw AbstractVM::IOperand::InvalidType();
}

AbstractVM::IOperand* AbstractVM::AOperand::operator-(const AbstractVM::IOperand &rhs) const
{
    auto type = OperandFactory::getWinningType(this->getType(), rhs.getType());
    if (AbstractVM::OperandFactory::isDecimal(type)) {
        double a = std::stod(this->toString());
        double b =  std::stod(rhs.toString());
        double result = a - b;
        if (b > 0 && result > a) throw AbstractVM::IOperand::Underflow();
        if (b < 0 && result < a) throw AbstractVM::IOperand::Overflow();
        return AbstractVM::OperandFactory::createOperand(type, doubleToString(result, getType() == AbstractVM::IOperand::eOperandType::Float));
    }
    if (AbstractVM::OperandFactory::isInt(type)) {
        int a = std::stoi(this->toString());
        int b = std::stoi(rhs.toString());
        int result = a - b;
        if (b > 0 && result > a) throw AbstractVM::IOperand::Underflow();
        if (b < 0 && result < a) throw AbstractVM::IOperand::Overflow();
        return AbstractVM::OperandFactory::createOperand(type, std::to_string(result));
    }
    throw AbstractVM::IOperand::InvalidType();
}

AbstractVM::IOperand* AbstractVM::AOperand::operator*(const AbstractVM::IOperand &rhs) const
{
    auto type = OperandFactory::getWinningType(this->getType(), rhs.getType());
    if (AbstractVM::OperandFactory::isDecimal(type)) {
        double result = std::stod(this->toString()) * std::stod(rhs.toString());
        return AbstractVM::OperandFactory::createOperand(type, doubleToString(result, getType() == AbstractVM::IOperand::eOperandType::Float));
    }
    if (AbstractVM::OperandFactory::isInt(type)) {
        int result = std::stoi(this->toString()) * std::stoi(rhs.toString());
        return AbstractVM::OperandFactory::createOperand(type, std::to_string(result));
    }
    throw AbstractVM::IOperand::InvalidType();
}

AbstractVM::IOperand* AbstractVM::AOperand::operator/(const AbstractVM::IOperand &rhs) const
{
    auto type = OperandFactory::getWinningType(this->getType(), rhs.getType());
    if (std::stoi(rhs.toString()) == 0) throw DivisionByZero();
    if (AbstractVM::OperandFactory::isDecimal(type)) {
        double result = std::stod(this->toString()) / std::stod(rhs.toString());
        return AbstractVM::OperandFactory::createOperand(type, doubleToString(result, getType() == AbstractVM::IOperand::eOperandType::Float));
    }
    if (AbstractVM::OperandFactory::isInt(type)) {
        int result = std::stoi(this->toString()) / std::stoi(rhs.toString());
        return AbstractVM::OperandFactory::createOperand(type, std::to_string(result));
    }
    throw AbstractVM::IOperand::InvalidType();
}

AbstractVM::IOperand* AbstractVM::AOperand::operator%(const AbstractVM::IOperand &rhs) const
{
    auto type = OperandFactory::getWinningType(this->getType(), rhs.getType());
    if (std::stoi(rhs.toString()) == 0) throw DivisionByZero();
    if (AbstractVM::OperandFactory::isDecimal(type)) {
        double result = std::fmod(std::stod(this->toString()), std::stod(rhs.toString()));
        return AbstractVM::OperandFactory::createOperand(type, doubleToString(result, getType() == AbstractVM::IOperand::eOperandType::Float));
    }
    if (AbstractVM::OperandFactory::isInt(type)) {
        int result = std::stoi(this->toString()) % std::stoi(rhs.toString());
        return AbstractVM::OperandFactory::createOperand(type, std::to_string(result));
    }
    throw AbstractVM::IOperand::InvalidType();
}

std::string AbstractVM::AOperand::doubleToString(double value, int precision) const
{
    if (value == 0) return "0.0";
    int x = int(std::floor(std::abs(value)));
    int count = 0;

    while (x > 0) {
        x /= 10;
        count++;
    }

    std::stringstream stream;
    stream << std::setprecision(precision + count) << value;
    return stream.str();
}

std::string AbstractVM::AOperand::doubleToString(double value, bool isFloat) const
{
    if (isFloat) return doubleToString(value, 7);
    return doubleToString(value, 15);
}
