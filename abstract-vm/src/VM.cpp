/*
** EPITECH PROJECT, 2022
** Source.cpp
** File description:
** Implement Source classes
*/

#include <sstream>
#include <algorithm>

#include "VM.hpp"
#include "OperandFactory.hpp"

AbstractVM::VM::VM(const Config& config) : _config(config)
{
    std::fill_n(_storage, 16, std::nullopt);
    _router["push"] = &AbstractVM::VM::push;
    _router["pop"] = &AbstractVM::VM::pop;
    _router["swap"] = &AbstractVM::VM::swap;
    _router["dup"] = &AbstractVM::VM::dup;
    _router["clear"] = &AbstractVM::VM::clear;
    _router["dump"] = &AbstractVM::VM::dump;
    _router["assert"] = &AbstractVM::VM::assert;
    _router["add"] = &AbstractVM::VM::add;
    _router["sub"] = &AbstractVM::VM::sub;
    _router["mul"] = &AbstractVM::VM::mul;
    _router["div"] = &AbstractVM::VM::div;
    _router["mod"] = &AbstractVM::VM::mod;
    _router["print"] = &AbstractVM::VM::print;
    _router["store"] = &AbstractVM::VM::store;
    _router["load"] = &AbstractVM::VM::load;
    _router["exit"] = &AbstractVM::VM::exit;
}

void AbstractVM::VM::execute(const std::string& line)
{
    if (finished()) return;
    std::vector<std::string> splitted;
    std::string sanitized = sanitize(line);
    if (_config.verbose) std::cout << "Executing: " << sanitized << std::endl;
    if (split(sanitized, splitted).size() == 0) return;
    router(splitted[0], splitted);
}

void AbstractVM::VM::router(const std::string& instruction, const std::vector<std::string>& args)
{
    if (_router.find(instruction) != _router.end()) return (_router.at(instruction))(this, args);
    throw InstructionNotFound(instruction);
}

void AbstractVM::VM::push(const std::vector<std::string>& args)
{
    if (args.size() != 2) throw InvalidInstruction();
    _stack.push_front(AbstractVM::OperandFactory::createOperand(args[1]));
}

void AbstractVM::VM::pop(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() == 0) throw StackTooSmall("pop");
    _stack.pop_front();
}

void AbstractVM::VM::clear(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    _stack.clear();
}

void AbstractVM::VM::dup(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() == 0) throw StackTooSmall("dup");
    _stack.push_front(AbstractVM::OperandFactory::createOperand(*_stack.front()));
}

void AbstractVM::VM::swap(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("swap");
    auto v1 = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto v2 = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    _stack.push_front(v1);
    _stack.push_front(v2);
}

void AbstractVM::VM::dump(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    for (auto it = _stack.begin(); it != _stack.end(); it++) {
        std::cout << (*it)->toString() << std::endl;
    }
}

void AbstractVM::VM::assert(const std::vector<std::string>& args)
{
    if (args.size() != 2) throw InvalidInstruction();
    if (_stack.size() == 0) throw StackTooSmall("assert");
    auto inputv = AbstractVM::OperandFactory::serialize(*AbstractVM::OperandFactory::createOperand(args[1]));
    std::string stackv = AbstractVM::OperandFactory::serialize(*_stack.front());
    if (stackv != inputv) throw AssertFail(stackv, inputv);
}

void AbstractVM::VM::add(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("add");
    auto tmp = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto result = *_stack.front() + *tmp;
    _stack.pop_front();
    _stack.push_front(result);
}

void AbstractVM::VM::sub(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("sub");
    auto tmp = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto result = *_stack.front() - *tmp;
    _stack.pop_front();
    _stack.push_front(result);
}

void AbstractVM::VM::mul(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("mul");
    auto tmp = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto result = *_stack.front() * *tmp;
    _stack.pop_front();
    _stack.push_front(result);
}

void AbstractVM::VM::div(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("div");
    auto tmp = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto result = *_stack.front() / *tmp;
    _stack.pop_front();
    _stack.push_front(result);
}

void AbstractVM::VM::mod(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() < 2) throw StackTooSmall("mod");
    auto tmp = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
    auto result = *_stack.front() % *tmp;
    _stack.pop_front();
    _stack.push_front(result);
}

void AbstractVM::VM::load(const std::vector<std::string>& args)
{
    if (args.size() != 2) throw InvalidInstruction();
    auto opslot = AbstractVM::OperandFactory::createOperand(args[1]);
    if (opslot->getType() > AbstractVM::IOperand::Int32) throw  InvalidInstruction();
    int slot = std::stoi(opslot->toString());
    if (slot > 15 || slot < 0) throw InvalidInstruction();
    if (!_storage[slot].has_value()) throw EmptySlot(slot);
    _stack.push_front(std::move(_storage[slot].value()));
    _storage[slot].reset();
}

void AbstractVM::VM::store(const std::vector<std::string>& args)
{
    if (args.size() != 2) throw InvalidInstruction();
    if (_stack.size() == 0) throw StackTooSmall("store");
    auto opslot = AbstractVM::OperandFactory::createOperand(args[1]);
    if (opslot->getType() > AbstractVM::IOperand::Int32) throw  InvalidInstruction();
    int slot = std::stoi(opslot->toString());
    if (slot > 15 || slot < 0) throw InvalidInstruction();
    _storage[slot] = AbstractVM::OperandFactory::createOperand(*_stack.front());
    _stack.pop_front();
}

void AbstractVM::VM::print(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    if (_stack.size() == 0) throw StackTooSmall("print");
    if (_stack.front()->getType() != AbstractVM::IOperand::eOperandType::Int8) throw InvalidArgument("print", AbstractVM::OperandFactory::serialize(*_stack.front()));
    int n = std::stoi(_stack.front()->toString());
    std::cout << static_cast<char>(n) << std::endl;
}

void AbstractVM::VM::exit(const std::vector<std::string>& args)
{
    if (args.size() != 1) throw InvalidInstruction();
    _exit = true;
}

bool AbstractVM::VM::finished() const
{
    return _exit;
}

std::string AbstractVM::VM::sanitize(const std::string& line)
{
    std::string sanitized;
    bool white_space = false;
    for (auto c : line) {
        if (c == ';') break;
        if (c == ' ' || c == '\t') {
            white_space = true;
        }
        if (white_space && c != ' ' && c != '\t') {
            sanitized += ' ';
            white_space = false;
        }
        if (!white_space) {
            sanitized += c;
        }
    }
    
    if (sanitized[0] == ' ') sanitized.erase(0, 1);

    return sanitized;
}

std::vector<std::string> &AbstractVM::VM::split(const std::string& line, std::vector<std::string> &splitted)
{
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        splitted.push_back(token);
    }
    return splitted;
}

