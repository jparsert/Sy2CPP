//
// Created by julian on 17.12.22.
//

#include "ast.h"

namespace Sy2CPP {

    std::string to_string(const EitherIdentifier &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

    std::string to_string(const EitherSort &ident) {
        return std::visit([](auto &id) mutable { return (std::string) id; }, ident);
    }

}