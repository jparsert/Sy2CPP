//
// Created by julian on 23.01.23.
//

#ifndef SY2CPP_EXCEPTIONS_H
#define SY2CPP_EXCEPTIONS_H


#include <exception>
#include <string>

namespace Sy2CPP {

    class IOException : std::exception {
    private:
        std::string msg;

    public:
        explicit IOException(std::string s) : msg{std::move(s)} {}

    };


    class not_implemented : std::exception {

        std::string msg;

    public:

        explicit not_implemented(std::string m) : msg{std::move(m)} {}

    };

    class TypingError : public std::exception {
        std::string msg;

    public:
        explicit TypingError(std::string m) : msg{std::move(m)} {}

    };

    class UnknownSymbol : public std::exception {

    private:
        std::string msg;

    public:
        explicit UnknownSymbol(std::string s) : msg{std::move(s)} {}

    };

    class unsupported_feature : std::exception {

        std::string msg;
    public:

        explicit unsupported_feature(std::string m) : msg{std::move(m)} {}

    };

    class WrongArguments : std::exception {

        std::string msg;

    public:

        explicit WrongArguments(std::string m) : msg{std::move(m)} {}

    };

}

#endif //SY2CPP_EXCEPTIONS_H
