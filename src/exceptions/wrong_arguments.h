//
// Created by julian on 17.01.23.
//

#ifndef PHYSER_WRONG_ARGUMENTS_H
#define PHYSER_WRONG_ARGUMENTS_H

#include <exception>
#include <string>

class WrongArguments : std::exception {

    std::string msg;

public:

    explicit WrongArguments(std::string m): msg{std::move(m)}{}

};


#endif //PHYSER_WRONG_ARGUMENTS_H
