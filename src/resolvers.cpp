//
// Created by julian on 28.12.22.
//

#include <optional>

#include "resolvers.h"
#include "exceptions.h"
#include "general_utility.h"
#include "AstPrinter.h"


namespace Sy2CPP {

    EitherSort FunctionDescriptor::get_range_sort() const {
        return this->range_sort;
    }

    std::vector<EitherSort> FunctionDescriptor::get_argument_sorts() const {
        return this->argument_sorts;
    }

    EitherIdentifier FunctionDescriptor::get_identifier() const {
        return this->id;
    }

    FunctionKind FunctionDescriptor::get_function_kind() const {
        return function_kind;
    }

    void FunctionDescriptor::set_function_kind(FunctionKind functionKind) {
        function_kind = functionKind;
    }

    FunctionDescriptor::operator std::string() const {
        std::stringstream res;
        res << "[" + to_string(this->get_identifier()) + ", (";
        if (!get_argument_sorts().empty()) {
            res << to_string(get_argument_sorts()[0]);

            for (int i = 1; i < get_argument_sorts().size(); ++i) {
                res << "," + to_string(get_argument_sorts()[i]);
            }
        }
        res << ") -> " + to_string(get_range_sort()) << ", " << to_string(get_function_kind()) << ", "
            << (is_chainable() ? "chainable" : "not chainable") << "]";
        return res.str();
    }

    std::optional<FunctionDescriptor>
    CoreResolver::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                             const std::vector<EitherSort> &arg_sorts) const {
        std::optional<FunctionDescriptor> special = CoreResolver::resolve_special_functions(identifier, arg_sorts);


        if (special.has_value()) {
            return special;
        }

        // get all elements with same id
        auto range = this->functions.equal_range(identifier);

        for (auto i = range.first; i != range.second; ++i) {
            const FunctionDescriptor &desc = i->second;
            if (desc.is_chainable()) {
                // check if all arg_sorts are equal
                if (all_elements_equal(arg_sorts)) {
                    if (arg_sorts[0] == desc.get_argument_sorts()[0]) {
                        return std::make_optional<FunctionDescriptor>(i->second);
                    }
                }
            } else { // same identifier (through map)
                if (desc.get_argument_sorts() == arg_sorts) {
                    return std::make_optional<FunctionDescriptor>(i->second);
                }
            }
        }

        return std::nullopt;
    }


    std::optional<FunctionDescriptor>
    CoreResolver::resolve_special_functions(const EitherIdentifier &identifier,
                                            const std::vector<EitherSort> &arg_sorts) {
        if (identifier.index() == 0) { // It is an SimpleIdentifier
            SimpleIdentifier id = std::get<0>(identifier);
            EitherSort bool_sort = CoreResolver::get_bool_sort();

            if (id.get_symbol() == "=" or id.get_symbol() == "distinct") {
                if (arg_sorts.size() < 2) {
                    throw WrongArguments("Less than 2 arguments for function " + id.get_symbol());
                }
                std::initializer_list<EitherSort> arg_lst1{bool_sort};

                if (all_elements_equal(arg_sorts)) {
                    //all are the same sort
                    return std::make_optional<FunctionDescriptor>(identifier, arg_lst1, bool_sort, FunctionKind::THEORY, true);
                }
            } else if (id.get_symbol() == "ite") {
                if (arg_sorts.size() != 3 or arg_sorts[0] != bool_sort or arg_sorts[1] != arg_sorts[2]) {
                    throw WrongArguments("Something went wrong with the types of ITE.");
                }
                return std::make_optional<FunctionDescriptor>(identifier, arg_sorts, arg_sorts[1], FunctionKind::THEORY, false);
            }
        }

        return std::nullopt;
    }

    CoreResolver::CoreResolver() {

        EitherSort bool_sort = CoreResolver::get_bool_sort();
        std::initializer_list<EitherSort> arg_lst1{bool_sort};
        std::initializer_list<EitherSort> arg_lst2{bool_sort, bool_sort};

        // Add NOT operator
        EitherIdentifier notId = get_simple_id_from_str("not");
        functions.emplace(notId, FunctionDescriptor(notId, arg_lst1, bool_sort, FunctionKind::THEORY,false));

        // Add => operator
        EitherIdentifier implId = get_simple_id_from_str("=>");
        functions.emplace(implId, FunctionDescriptor(implId, arg_lst2, bool_sort, FunctionKind::THEORY, false));

        // Add and operator
        EitherIdentifier andId = get_simple_id_from_str("and");
        functions.emplace(andId, FunctionDescriptor(andId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add or operator
        EitherIdentifier orId = get_simple_id_from_str("or");
        functions.emplace(orId, FunctionDescriptor(orId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

        // Add xor operator
        EitherIdentifier xorId = get_simple_id_from_str("xor");
        functions.emplace(xorId, FunctionDescriptor(xorId, arg_lst1, bool_sort, FunctionKind::THEORY, true));

    }

    std::optional<SortDescriptor> CoreResolver::lookup_or_resolve_sort(const EitherSort &sort) const {
        return sort == CoreResolver::get_bool_sort() ? std::make_optional<SortDescriptor>(CoreResolver::get_bool_sort(), SortKind::PRIMITIVE) : std::nullopt;
    }


    std::optional<FunctionDescriptor>
    LIAResolver::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                            const std::vector<EitherSort> &arg_sorts) const {
        std::optional<FunctionDescriptor> special = LIAResolver::resolve_special_functions(identifier, arg_sorts);
        if (special.has_value()) {
            return special;
        }

        // get all elements with same id
        auto range = this->functions.equal_range(identifier);

        for (auto i = range.first; i != range.second; ++i) {
            const FunctionDescriptor &desc = i->second;
            if (desc.is_chainable()) {
                // check if all arg_sorts are equal
                if (all_elements_equal(arg_sorts)) {
                    if (arg_sorts[0] == desc.get_argument_sorts()[0]) {
                        return std::make_optional<FunctionDescriptor>(desc);
                    }
                }
            } else { // same identifier (through map)
                if (desc.get_argument_sorts() == arg_sorts) {
                    return std::make_optional<FunctionDescriptor>(desc);
                }
            }
        }

        return std::nullopt;

    }

    std::optional<FunctionDescriptor>
    LIAResolver::resolve_special_functions(const EitherIdentifier &identifier,
                                           const std::vector<EitherSort> &arg_sorts) {
        if (identifier.index() == 0) {
            SimpleIdentifier id = std::get<0>(identifier);

            EitherSort int_sort = LIAResolver::get_int_sort();
            std::initializer_list<EitherSort> arg_lst1{int_sort};
            std::initializer_list<EitherSort> arg_lst2{int_sort,int_sort};

            if (id.get_symbol() == "-" and arg_sorts.size() == 1 and arg_sorts[0] == LIAResolver::get_int_sort()) {
                EitherIdentifier uminus = get_simple_id_from_str("-");
                return std::make_optional<FunctionDescriptor>(uminus, arg_lst1, int_sort, FunctionKind::THEORY, false);

            } else if (id.get_symbol() == "-" and
                       arg_sorts.size() > 1 and
                       all_elements_equal(arg_sorts) and
                       arg_sorts[0] == LIAResolver::get_int_sort()) {

                EitherIdentifier minus = get_simple_id_from_str("-");
                return std::make_optional<FunctionDescriptor>(minus, arg_lst2, int_sort, FunctionKind::THEORY, false);

            }
        }
        return std::nullopt;
    }

    LIAResolver::LIAResolver() {
        EitherSort bool_sort = CoreResolver::get_bool_sort();
        EitherSort int_sort = LIAResolver::get_int_sort();
        std::initializer_list<EitherSort> arg_lst1{int_sort};
        std::initializer_list<EitherSort> arg_lst2{int_sort, int_sort};

        // Add unary - operator
        EitherIdentifier uminus = get_simple_id_from_str("-");
        functions.emplace(uminus, FunctionDescriptor(uminus, arg_lst1, int_sort, FunctionKind::THEORY, false));

        // Add multi - operator
        EitherIdentifier minus = get_simple_id_from_str("-");
        functions.emplace(minus, FunctionDescriptor(minus, arg_lst2, int_sort, FunctionKind::THEORY, false));

        // Add abs operator
        EitherIdentifier abs = get_simple_id_from_str("abs");
        functions.emplace(abs, FunctionDescriptor(abs, arg_lst1, int_sort, FunctionKind::THEORY, false));

        // Add mod  operator
        EitherIdentifier mod = get_simple_id_from_str("mod");
        functions.emplace(mod, FunctionDescriptor(mod, arg_lst2, int_sort, FunctionKind::THEORY, false));

        // Add + operator
        EitherIdentifier plus = get_simple_id_from_str("+");
        functions.emplace(plus, FunctionDescriptor(plus, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add * operator
        EitherIdentifier times = get_simple_id_from_str("*");
        functions.emplace(times, FunctionDescriptor(times, arg_lst1, int_sort, FunctionKind::THEORY, true));

        // Add div operator
        EitherIdentifier div = get_simple_id_from_str("div");
        functions.emplace(div, FunctionDescriptor(div, arg_lst2, int_sort, FunctionKind::THEORY, false));

        // Add div operator
        EitherIdentifier less = get_simple_id_from_str("<");
        functions.emplace(less, FunctionDescriptor(less, arg_lst2, bool_sort, FunctionKind::THEORY, false));

        // Add div operator
        EitherIdentifier leq = get_simple_id_from_str("<=");
        functions.emplace(leq, FunctionDescriptor(leq, arg_lst2, bool_sort, FunctionKind::THEORY, false));

        // Add div operator
        EitherIdentifier ge = get_simple_id_from_str(">");
        functions.emplace(ge, FunctionDescriptor(ge, arg_lst2, bool_sort, FunctionKind::THEORY, false));

        // Add div operator
        EitherIdentifier geq = get_simple_id_from_str(">=");
        functions.emplace(geq, FunctionDescriptor(geq, arg_lst2, bool_sort, FunctionKind::THEORY, false));

    }

    std::optional<SortDescriptor> LIAResolver::lookup_or_resolve_sort(const EitherSort &sort) const {
        return sort == LIAResolver::get_int_sort() ?
        std::make_optional<SortDescriptor>(LIAResolver::get_int_sort(), SortKind::PRIMITIVE) : std::nullopt;
    }

    EitherSort LIAResolver::get_int_sort()  {
        return get_simple_sort_from_str("Int");
    }

    const EitherIdentifier &SymbolDescriptor::get_identifier() const {
        return symbol;
    }


    const EitherSort &SymbolDescriptor::get_symbol_sort() const {
        return symbol_sort;
    }


    BinderKind SymbolDescriptor::get_binder() const {
        return binder;
    }

    bool SymbolDescriptor::operator==(const SymbolDescriptor &desc) const {
        return this->get_identifier() == desc.get_identifier() and
                this->get_binder() == desc.get_binder() and
                this->get_symbol_sort() == desc.get_symbol_sort();
    }

    bool SymbolDescriptor::operator!=(const SymbolDescriptor &desc) const {
        return not (*this == desc);
    }

    const EitherSort &SortDescriptor::get_sort() const {
        return sort;
    }

    void SortDescriptor::set_sort(const EitherSort &srt) {
        this->sort = srt;
    }

    SortKind SortDescriptor::get_sort_kind() const {
        return sort_kind;
    }

    void SortDescriptor::set_sort_kind(SortKind sortKind) {
        sort_kind = sortKind;
    }

    bool operator==(const FunctionDescriptor &lhs, const FunctionDescriptor &rhs) {
        return lhs.get_identifier() == rhs.get_identifier() and
               lhs.get_argument_sorts() == rhs.get_argument_sorts() and
               lhs.get_range_sort() == rhs.get_range_sort() and
               lhs.is_chainable() == rhs.is_chainable();
    }

    BVResolver::BVResolver() {

        std::initializer_list<EitherSort> one_arg{get_bv_sort(0)};
        std::initializer_list<EitherSort> two_arg{get_bv_sort(0), get_bv_sort(0)};

        // UNARY
        {
            EitherIdentifier bvnot = SimpleIdentifier("bvnot");
            functions.emplace(bvnot, FunctionDescriptor(bvnot, one_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier bvneg = SimpleIdentifier("bvneg");
            functions.emplace(bvneg, FunctionDescriptor(bvneg, one_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        // BINARY  not CHAINABLE
        {
            SimpleIdentifier sym = SimpleIdentifier("bvurem");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsrem");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsmod");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvshl");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvlshr");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvashr");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, get_bv_sort(0), FunctionKind::THEORY, false));
        }
        // ARithmetic chainable
        {
            SimpleIdentifier sym = SimpleIdentifier("bvand");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvor");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvnand");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvnor");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvxor");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvxnor");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvadd");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsub");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvmul");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvudiv");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsdiv");
            functions.emplace(sym, FunctionDescriptor(sym, one_arg, get_bv_sort(0), FunctionKind::THEORY, true));
        }
        // COMPARISONs
        {
            SimpleIdentifier sym = SimpleIdentifier("bvult");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvule");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvugt");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvuge");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg,CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvslt");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsle");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsgt");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }
        {
            SimpleIdentifier sym = SimpleIdentifier("bvsge");
            functions.emplace(sym, FunctionDescriptor(sym, two_arg, CoreResolver::get_bool_sort(), FunctionKind::THEORY, false));
        }

    }

    EitherSort BVResolver::get_bv_sort(long bits) {
        return {SimpleSort(get_indexed_identifier(bit_vec_string, bits))};
    }

    std::optional<FunctionDescriptor> BVResolver::lookup_or_resolve_function(const EitherIdentifier &identifier,
                                                                             const std::vector<EitherSort> &arg_sorts) const {

        std::optional<FunctionDescriptor> special = BVResolver::resolve_special_functions(identifier, arg_sorts);
        if (special.has_value()) {
            return special;
        }

        // get all elements with same id

        auto range = this->functions.equal_range(identifier);

        // check that first argument is a bitvector
        if(arg_sorts[0].index() == 0) {
            SimpleSort sort = std::get<SimpleSort>(arg_sorts[0]);
            if (sort.get_identifier().index() == 1) {
                IndexedIdentifier id = std::get<IndexedIdentifier>(sort.get_identifier());
                if (id.get_simple_identifier() != SimpleIdentifier(bit_vec_string)) {
                    return std::nullopt;
                }
            } else {
                return std::nullopt;
            }
        } else  {
            return std::nullopt;
        }

        // check if each argument sort is the same as the first
        if (!all_elements_equal(arg_sorts)) {
            return std::nullopt;
        }

        for (auto i = range.first; i != range.second; ++i) {
            FunctionDescriptor desc = i->second;
            desc.set_range_sort(arg_sorts[0]); // Add the range sort to refelct the bits of the resulting vector. Bit default it's zero

            if (desc.is_chainable()) {
                return std::make_optional<FunctionDescriptor>(desc);

            } else { // same identifier (through map)
                if (desc.get_argument_sorts().size() == arg_sorts.size()) {
                    return std::make_optional<FunctionDescriptor>(desc);
                }

            }
        }

        return std::nullopt;

    }

    std::optional<SortDescriptor> BVResolver::lookup_or_resolve_sort(const EitherSort &sort) const {
        if (sort.index() == 0) {
            SimpleSort srt = std::get<SimpleSort>(sort);
            EitherIdentifier id = srt.get_identifier();
            if (id.index() == 1) {
                IndexedIdentifier ind_id = std::get<IndexedIdentifier>(id);
                auto indices = ind_id.get_indices();
                if (indices.size() == 1) {
                    if (indices[0].index() == 0) { // Is numeral not symbol
                        return std::make_optional<SortDescriptor>(get_bv_sort(std::get<Numeral>(indices[0]).get_value()), SortKind::PRIMITIVE);
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }

            } else {
                return std::nullopt;
            }
        } else {
            return std::nullopt;
        }
    }

    std::optional<FunctionDescriptor> BVResolver::resolve_special_functions(const EitherIdentifier &identifier,
                                                                            const std::vector<EitherSort> &arg_sorts) {
        //TODO concat and extract

        return std::optional<FunctionDescriptor>();
    }
}

namespace std {
    std::size_t hash<Sy2CPP::SortDescriptor>::operator()(const Sy2CPP::SortDescriptor &sd) {
        return hash_combine(
                std::hash<Sy2CPP::EitherSort>{}(sd.get_sort()),
                static_cast<std::size_t>(sd.get_sort_kind()));
    }

    std::size_t hash<Sy2CPP::FunctionDescriptor>::operator()(const Sy2CPP::FunctionDescriptor &fd) const {
        return hash_combine(
                std::hash<Sy2CPP::EitherIdentifier>{}(fd.get_identifier()),
                hash_vector(fd.get_argument_sorts()),
                std::hash<Sy2CPP::EitherSort>{}(fd.get_range_sort()),
                static_cast<std::size_t>(fd.get_function_kind()),
                static_cast<std::size_t>(fd.is_chainable())
        );
    }

    std::size_t hash<Sy2CPP::FunctionDescriptor&>::operator()(const Sy2CPP::FunctionDescriptor &fd) const {
        return hash_combine(
                std::hash<Sy2CPP::EitherIdentifier>{}(fd.get_identifier()),
                hash_vector(fd.get_argument_sorts()),
                std::hash<Sy2CPP::EitherSort>{}(fd.get_range_sort()),
                static_cast<std::size_t>(fd.get_function_kind()),
                static_cast<std::size_t>(fd.is_chainable())
        );
    }

    std::size_t hash<Sy2CPP::SymbolDescriptor>::operator()(const Sy2CPP::SymbolDescriptor &symbD) {
        return hash_combine(
                std::hash<Sy2CPP::EitherIdentifier>{}(symbD.get_identifier()),
                std::hash<Sy2CPP::EitherSort>{}(symbD.get_symbol_sort()),
                static_cast<std::size_t>(symbD.get_binder()));
    }
}
