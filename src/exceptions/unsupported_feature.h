//
// Created by julian on 13.12.22.
//

#ifndef PHYSER_UNSUPPORTED_FEATURE_H
#define PHYSER_UNSUPPORTED_FEATURE_H

#include <exception>
#include <string>
#include <utility>


class unsupported_feature : std::exception {

    std::string msg;
public:

    explicit unsupported_feature(std::string m): msg{std::move(m)}{}

};


#endif //PHYSER_UNSUPPORTED_FEATURE_H
