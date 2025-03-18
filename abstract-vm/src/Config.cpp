/*
** EPITECH PROJECT, 2022
** Config.cpp
** File description:
** Implement Config class
*/

#include "Config.hpp"

AbstractVM::Config::Config(int argc, const char* argv[]) : _args(argc, argv)
{
    std::string prevent_ = _args.getOption("prevent").value_or(_args.getOption("p").value_or("false"));
    if (prevent_ == "" || prevent_ == "true" || prevent_ == "1") exitOnError = false;

    std::string input_ = _args.getOption("input").value_or(_args.getOption("i").value_or("file"));
    if (input_ == "stdin") input = STDIN;
    if (input_ == "bash") input = BASH;
    if (input_ == "file") input = FILE;

    std::string verbose_ = _args.getOption("verbose").value_or(_args.getOption("v").value_or("false"));
    if (verbose_ == "" || verbose_ == "true" || verbose_ == "1") verbose = true;

    file = _args.getOption("file").value_or(_args.getOption("f").value_or(_args.getRest()));
    if (input == FILE && file == "") input = STDIN;
}
