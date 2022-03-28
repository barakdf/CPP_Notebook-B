#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

namespace page {
    class Page {
    public:
        std::unordered_map<int, std::string> page;

        void row_write(int row, int col, const std::string &text, bool new_l);
        void col_write(int row, int col, const std::string &text, bool new_page);
    };
}