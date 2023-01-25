//
// Created by julian on 23.01.23.
//

#include "exceptions.h"


std::string Sy2CPP::IOException::what() {
    return msg;
}

std::string Sy2CPP::NotImplemented::what() {
    return msg;
}

std::string Sy2CPP::TypingError::what() {
    return msg;
}

std::string Sy2CPP::UnknownSymbol::what() {
    return msg;
}

std::string Sy2CPP::UnsupportedFeature::what() {
    return msg;
}

std::string Sy2CPP::WrongArguments::what() {
    return msg;
}
