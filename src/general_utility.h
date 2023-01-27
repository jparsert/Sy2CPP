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

template<typename T>
bool all_elements_equal(std::vector<T> vec) {
    if (vec.empty()) {
        return true;
    }

    return all_of( vec.begin(),
                   vec.end(),
                   [&](const T& value){
                       return value == *(vec.begin());
                   });
}



// Hash function and constants taken from
// https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector/72073933#72073933
template<typename T>
std::size_t hash_vector(const std::vector<T>& vec) {
    std::size_t seed = vec.size();
    for(const auto& el : vec) {
        size_t x = std::hash<T>{}(el);
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

// Hash function and constants taken from
//  https://stackoverflow.com/questions/2590677/how-do-i-combine-hash-values-in-c0x
template <typename T, typename... Rest>
void hash_combine(std::size_t& seed, const T& v, const Rest&... rest)
{
    seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    (hash_combine(seed, rest), ...);
}

template <typename T, typename... Rest>
size_t hash_combine(const T& v, const Rest&... rest)
{
    size_t seed = 0;
    seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    (hash_combine(seed, rest), ...);

    return seed;
}


#endif //PHYSER_GENERAL_UTILITY_H
