/*
** EPITECH PROJECT, 2022
** Arguments.hpp
** File description:
** A class to handle arguments passed to program
*/

#ifndef _ABSTRACT_VM_ARGUMENTS_HPP_
#define _ABSTRACT_VM_ARGUMENTS_HPP_

#include <string>
#include <optional>
#include <map>
#include <iostream>

#define USAGE "USAGE: ./avm [file]\n" \
    "\t-f, --file\tSet the file as option (only when input is set at 'file')\n" \
    "\t-i, --input\tSet the input mode only 'stdin', 'bash' and 'file' are avaible (default: 'file')\n" \
    "\t-v, --verbose\tDisplay more contextual information\n" \
    "\t-p, --prevent\tPrevent exit on error"

namespace AbstractVM
{
    class Arguments {
        public:
            Arguments(int argc, const char* argv[]);
            ~Arguments() = default;

            std::optional<std::string> getOption(const std::string& option) const;
            std::string getRest() const;

            class InvalidArgumentShort : public std::runtime_error {
                public:
                    InvalidArgumentShort(const std::string& option) : std::runtime_error("Invalid short option: " + option) {}
            };
            
            class RestAlreayDefined : public std::runtime_error {
                public:
                    RestAlreayDefined() : std::runtime_error(USAGE) {}
            };

        private:
            Arguments() = delete;

            static std::string getOptionName(const std::string& option);

            std::map<std::string, std::string> _options;
            std::string _rest = "";
    };
}

#endif
