/*
** EPITECH PROJECT, 2022
** Source.hpp
** File description:
** Classes to get the input to the right place
*/

#ifndef _ABSTRACT_VM_SOURCE_HPP_
#define _ABSTRACT_VM_SOURCE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Config.hpp"

namespace AbstractVM
{
    class ISource {
        public:
            virtual ~ISource() = default;

            virtual std::string getline() = 0;

            static std::unique_ptr<ISource> create(const Config& config);

            class NoLine : public std::runtime_error {
                public:
                    NoLine() : std::runtime_error("No line to read") {}
            };

            class InvalidSource : public std::runtime_error {
                public:
                    InvalidSource() : std::runtime_error("Invalid source") {}
            };
    };

    class StdinSource : public ISource {
        public:
            ~StdinSource() = default;

            std::string getline() override;
    };

    class BashSource : public StdinSource {
        public:
            ~BashSource() = default;

            std::string getline() override;
    };

    class FileSource : public ISource {
        public:
            FileSource(const std::string& path);
            ~FileSource() = default;

            std::string getline() override;

            class FileNotFound : public std::runtime_error {
                public:
                    FileNotFound(const std::string& path) : std::runtime_error("File not found: " + path) {}
            };

        private:
            std::ifstream _file;
    };

}

#endif
