//
// Created by julian on 12.12.22.
//

#include "sygus_smt_rep.h"

std::string sygus_smt_rep::get_logic() const {
    return this->logic;
}

void sygus_smt_rep::set_logic(const std::string& ll) {
    this->logic = ll;
}

z3::context& sygus_smt_rep::get_context() {
    return this->ctx;
}
