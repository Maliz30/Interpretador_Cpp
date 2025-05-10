#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

struct  Symbol {
    std::string name;
    std::string type;
    Symbol(std::string name, std::string type)
        : name(std::move(name)), type(std::move(type)),  {}
};

#endif