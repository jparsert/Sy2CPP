//
// Created by julian on 17.12.22.
//

#include "ast.h"


std::string to_string(const EitherIdentifier& ident) {
    return std::visit([](auto& id) mutable {return (std::string)id;}, ident);
}