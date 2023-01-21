//
// Created by julian on 24.12.22.
//

#ifndef PHYSER_UNKNOWNSYMBOL_H
#define PHYSER_UNKNOWNSYMBOL_H


#include <exception>
#include <string>

namespace Sy2CPP {

    class UnknownSymbol : public std::exception {

    private:
        std::string msg;

    public:
        explicit UnknownSymbol(std::string s) : msg{std::move(s)} {}

    };
}
#endif //PHYSER_UNKNOWNSYMBOL_H
