//
// Created by julian on 14.12.22.
//

#ifndef PHYSER_NOT_IMPLEMENTED_H
#define PHYSER_NOT_IMPLEMENTED_H

#include <exception>
#include <string>
#include <utility>

class not_implemented : std::exception {

    std::string msg;

public:

    explicit not_implemented(std::string m): msg{std::move(m)}{}

};


#endif //PHYSER_NOT_IMPLEMENTED_H
