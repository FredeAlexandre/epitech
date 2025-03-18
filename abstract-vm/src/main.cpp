/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Entry point of the program
*/

#include <iostream>
#include "Config.hpp"
#include "Source.hpp"
#include "VM.hpp"

int main(int argc, const char* argv[])
{
    try {
        AbstractVM::Config config(argc, argv);
        std::unique_ptr<AbstractVM::ISource> source = AbstractVM::ISource::create(config);
        AbstractVM::VM vm(config);
        std::string line;
        int i = 0;
        while (true) {
            try {
                line = source->getline();
                i++;
            } catch(const AbstractVM::ISource::NoLine& e) {
                if (vm.finished()) break;
                std::cerr << "Missing exit command" << std::endl;
                return 84;
            }
            try {
                vm.execute(line);
            } catch(const std::exception& e) {
                std::cerr << "line " << i << ": " << e.what() << std::endl;
                if (config.exitOnError)
                    return 84;
            }
        }
        return 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
