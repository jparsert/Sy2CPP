//
// Created by julian on 28.12.22.
//


#include "ast.h"

#ifndef PHYSER_RESOLVERS_H
#define PHYSER_RESOLVERS_H




class AbstractResolver {


public:

    virtual FunctionDeclaration find_or_resolve_symbol(std::string& symbol) = 0;





};

#endif //PHYSER_RESOLVERS_H
