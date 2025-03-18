/*
** EPITECH PROJECT, 2022
** arcade.hpp
** File description:
** The common layer of the Arcade project
*/

#include <dlfcn.h>
#include <filesystem>

#include "loaders.hpp"

Loader::Loader(const std::string &path)
{
    if (!std::filesystem::exists(path)) throw std::runtime_error("Library: " + path + " not found");
    Handler = dlopen(path.c_str(), RTLD_LAZY);
    if (Handler == nullptr) throw std::runtime_error("Library: " + path + " can't be openned because: " + dlerror());
}

Loader::~Loader()
{
    dlclose(Handler);
}
