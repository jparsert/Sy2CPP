//
// Created by julian on 21.12.22.
//

#ifndef PHYSER_IOEXCEPTION_H
#define PHYSER_IOEXCEPTION_H

#include <exception>
#include <string>


class IOException : std::exception {
private:
    std::string msg;

public:
    explicit IOException(std::string s): msg{std::move(s)} {}

};


#endif //PHYSER_IOEXCEPTION_H
