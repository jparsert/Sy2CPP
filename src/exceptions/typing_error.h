//
// Created by julian on 19.01.23.
//

#ifndef PHYSER_TYPING_ERROR_H
#define PHYSER_TYPING_ERROR_H

#include <exception>
#include <string>

namespace Sy2CPP {

    class TypingError : public std::exception {
        std::string msg;

    public:
        explicit TypingError(std::string m) : msg{std::move(m)} {}

    };

}
#endif //PHYSER_TYPING_ERROR_H
