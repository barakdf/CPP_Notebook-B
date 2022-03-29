#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

namespace page {
    class Page {
    public:
        std::unordered_map<int, std::string> page;

        bool row_write(int row, int col, const std::string &text, bool new_l);
        bool col_write(int row, int col, const std::string &text, bool new_page);
        void row_erase(int row, int col, int len, bool new_page);
        void col_erase(int row, int col, int len, bool new_page);
    };
}