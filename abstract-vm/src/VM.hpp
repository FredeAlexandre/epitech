/*
** EPITECH PROJECT, 2022
** VM.hpp
** File description:
** The VM class
*/

#ifndef _ABSTRACT_VM_VM_HPP_
#define _ABSTRACT_VM_VM_HPP_

#include <string>
#include <list>
#include <vector>

#include "Config.hpp"
#include "IOperand.hpp"

namespace AbstractVM
{
    class VM {
        public:
            VM(const Config& config);
            ~VM() = default;

            void execute(const std::string& line);

            void router(const std::string& instruction, const std::vector<std::string>& args);

            void push(const std::vector<std::string>& args);
            void pop(const std::vector<std::string>& args);
            void clear(const std::vector<std::string>& args);
            void dup(const std::vector<std::string>& args);
            void swap(const std::vector<std::string>& args);
            void dump(const std::vector<std::string>& args);
            void assert(const std::vector<std::string>& args);
            void add(const std::vector<std::string>& args);
            void sub(const std::vector<std::string>& args);
            void mul(const std::vector<std::string>& args);
            void div(const std::vector<std::string>& args);
            void mod(const std::vector<std::string>& args);
            void load(const std::vector<std::string>& args);
            void store(const std::vector<std::string>& args);
            void print(const std::vector<std::string>& args);
            void exit(const std::vector<std::string>& args);

            bool finished() const;

            class InvalidInstruction : public std::runtime_error {
                public:
                    InvalidInstruction() : std::runtime_error("Invalid instruction or argument passed") {}
            };

            class InstructionNotFound : public std::runtime_error {
                public:
                    InstructionNotFound(const std::string &instruction) : std::runtime_error(instruction + " has not been implemented") {}
            };

            class InvalidArgument : public std::runtime_error {
                public:
                    InvalidArgument(const std::string &instruction, const std::string &argument) : std::runtime_error("Argument: " + argument + " is invalid in " + instruction) {}
            };

            class StackTooSmall : public std::runtime_error {
                public:
                    StackTooSmall(const std::string &instruction) : std::runtime_error("Stack is too small to perform " + instruction) {}
            };

            class EmptySlot : public std::runtime_error {
                public:
                    EmptySlot(int slot) : std::runtime_error("Slot " + std::to_string(slot) + " is empty") {}
            };

            class AssertFail : public std::runtime_error {
                public:
                    AssertFail(const std::string &actual, const std::string &expected) : std::runtime_error("Assert failed ! received: " + expected + ", stack: " + actual) {}
            };

        private:
            VM() = delete;
            std::list<AbstractVM::IOperand*> _stack;
            std::optional<AbstractVM::IOperand*> _storage[16] = {};

            static std::string sanitize(const std::string& line);
            static std::vector<std::string> &split(const std::string& line, std::vector<std::string> &splitted);

            bool _exit = false;
            const Config &_config;
            std::map<std::string, std::function<void(VM*, const std::vector<std::string>&)>> _router;
    };
}

#endif
