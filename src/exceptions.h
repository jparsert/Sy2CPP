//
// Created by julian on 23.01.23.
//

#ifndef SY2CPP_EXCEPTIONS_H
#define SY2CPP_EXCEPTIONS_H


#include <exception>
#include <string>

namespace Sy2CPP {

    class Sy2CPPException: std::exception {
    public:
        virtual std::string what() = 0;
    };


    class IOException : public Sy2CPPException {
    private:
        std::string msg;

    public:
        explicit IOException(std::string s) : msg{std::move(s)} {}

        std::string what() override;

    };


    class NotImplemented : public Sy2CPPException {

        std::string msg;

    public:

        explicit NotImplemented(std::string m) : msg{std::move(m)} {}
        std::string what() override;

    };

    class TypingError : public Sy2CPPException {
        std::string msg;

    public:
        explicit TypingError(std::string m) : msg{std::move(m)} {}
        std::string what() override;

    };

    class UnknownSymbol : public Sy2CPPException {

    private:
        std::string msg;

    public:
        explicit UnknownSymbol(std::string s) : msg{std::move(s)} {}
        std::string what() override;

    };

    class UnsupportedFeature : Sy2CPPException {

        std::string msg;
    public:

        explicit UnsupportedFeature(std::string m) : msg{std::move(m)} {}
        std::string what() override;

    };

    class WrongArguments : Sy2CPPException {

        std::string msg;

    public:

        explicit WrongArguments(std::string m) : msg{std::move(m)} {}
        std::string what() override;

    };

}

#endif //SY2CPP_EXCEPTIONS_H
