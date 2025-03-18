/*
** EPITECH PROJECT, 2022
** Source.cpp
** File description:
** Implement Source classes
*/

#include "Source.hpp"

std::unique_ptr<AbstractVM::ISource> AbstractVM::ISource::create(const AbstractVM::Config &config)
{
    switch (config.input) {
        case AbstractVM::Config::Input::STDIN:
            return std::make_unique<AbstractVM::StdinSource>();
        case AbstractVM::Config::Input::BASH:
            return std::make_unique<AbstractVM::BashSource>();
        case AbstractVM::Config::Input::FILE:
            return std::make_unique<AbstractVM::FileSource>(config.file);
    }
    throw InvalidSource();
}

std::string AbstractVM::StdinSource::getline()
{
    std::string line;

    if (!std::getline(std::cin, line)) throw NoLine();
    if (line == ";;") throw NoLine();
    return line;
}

std::string AbstractVM::BashSource::getline()
{
    std::cout << "> ";
    return AbstractVM::StdinSource::getline();
}

AbstractVM::FileSource::FileSource(const std::string& path)
{
    _file.open(path);
    if (!_file.is_open()) throw FileNotFound(path);
}

std::string AbstractVM::FileSource::getline()
{
    std::string line;

    if (!std::getline(_file, line)) throw NoLine();
    return line;
}
