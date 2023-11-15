//
// Created by julian on 15.11.23.
//

#include "utils.h"

#include <string>
#include <vector>
#include <filesystem>

std::vector<std::string> files_with_suffix_in_dirs(const std::vector<std::string>& dirs, const std::string& suffix) {
    std::vector<std::string> res;

    for (auto& dir : dirs) {
        if (std::filesystem::is_regular_file(dir)) {
            if (dir.ends_with(suffix)) {
                res.push_back(dir);
            }
            continue;
        } else {
            for (const auto &entry: std::filesystem::recursive_directory_iterator(dir)) {
                if (entry.path().string().ends_with(suffix)) {
                    res.push_back(entry.path().string());
                }
            }
        }
    }

    return res;
}