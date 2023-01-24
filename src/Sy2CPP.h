//
// Created by julian on 23.01.23.
//

#ifndef SY2CPP_SY2CPP_H
#define SY2CPP_SY2CPP_H


#include <tuple>

#include "symbol_table.h"

namespace Sy2CPP {

    std::pair<std::shared_ptr<SymbolTable>, std::shared_ptr<Problem>>
    get_symbol_table_and_ast_from_file(const std::string& path);

}


#endif //SY2CPP_SY2CPP_H
