/*
** EPITECH PROJECT, 2022
** Config.hpp
** File description:
** A class to wrap Arguments and store how the program should behave
*/

#ifndef _ABSTRACT_VM_CONFIG_HPP_
#define _ABSTRACT_VM_CONFIG_HPP_

#include "Arguments.hpp"

namespace AbstractVM
{

    class Config {
        public:
            Config(int argc, const char* argv[]);
            ~Config() = default;

            enum Input {
                STDIN,
                BASH,
                FILE
            };

            Input input = FILE;
            bool verbose = false;
            std::string file = "";
            bool exitOnError = true;

            class NoFileInput : public std::runtime_error {
                public:
                    NoFileInput() : std::runtime_error(USAGE) {}
            };

        private:
            Arguments _args;
    };
}

#endif
