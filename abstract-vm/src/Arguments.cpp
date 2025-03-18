/*
** EPITECH PROJECT, 2022
** Arguments.cpp
** File description:
** Implement Arguments class
*/

#include "Arguments.hpp"

AbstractVM::Arguments::Arguments(int argc, const char* argv[])
{
    std::string option;

    for (int i = 1; i < argc; i++) {
        std::string arg = AbstractVM::Arguments::getOptionName(argv[i]);
        bool is_option = arg != "";
        if (!is_option) arg = argv[i];

        if (is_option) {
            _options[arg] = "";
            option = arg;
            continue;
        }

        if (!is_option && option == "") {
            if (_rest != "") throw RestAlreayDefined();
            _rest = arg;
        } else {
            _options[option] = arg;
            option = "";
        }
    }
}

std::optional<std::string> AbstractVM::Arguments::getOption(const std::string &option) const
{
    if (_options.find(option) == _options.end()) return std::nullopt;
    return _options.at(option);
}

std::string AbstractVM::Arguments::getRest() const
{
    return _rest;
}

std::string AbstractVM::Arguments::getOptionName(const std::string &option)
{
    int dashes = 0;
    if (option[0] == '-') {
        dashes++;
        if (option[1] == '-')
            dashes++;
    }

    if (dashes == 1) {
        if (option.size() != 2)
            throw InvalidArgumentShort(option);
        return option.substr(1, 1);
    }
    if (dashes == 2) return option.substr(2);
    return "";
}
