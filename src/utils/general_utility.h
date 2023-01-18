//
// Created by julian on 17.01.23.
//

#ifndef PHYSER_GENERAL_UTILITY_H
#define PHYSER_GENERAL_UTILITY_H

#include <memory>
#include <vector>

template<typename T>
bool equal_shared_ptr_vectors(std::vector<std::shared_ptr<T>> vec1, std::vector<std::shared_ptr<T>> vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    // Maybe use nice iterators
    for(auto i = 0; i < vec1.size(); ++i) {
        if (*vec1[i] != *vec2[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool all_shared_ptr_elements_equal(std::vector<std::shared_ptr<T>> vec) {
    return all_of(vec.begin(), vec.end(), [&] (std::shared_ptr<T>& i) {return *i == *vec[0];});
}


#endif //PHYSER_GENERAL_UTILITY_H
