#include <iostream>
#include <unordered_map>
#include "Page.hpp"

using namespace std;

using namespace page;

static const int line_len = 100;

bool Page::row_write(int row, int col, const string &text, bool new_l) {
    string new_line;
    new_line.append(line_len, '_');
    if (new_l) {
        this->page.insert({row, new_line});
    } else {
        if (this->page.find(row) == this->page.end()) {
            this->page.insert({row, new_line});
        }
        for (int i = col; i < (unsigned long) col + text.size(); ++i) {
            if (this->page.at(row).at((unsigned long) i) != '_') {
                return false;
            }
        }
    }
//    this->page.at(row).replace((unsigned long) col, text.size(), text);
    unsigned long j = 0;
    for (int i = col; i < (unsigned long)col + text.size(); ++i) {
        this->page.at(row).at((unsigned long) i) = text.at(j++);
    }
    return true;
}

bool Page::col_write(int row, int col, const std::string &text, bool new_page) {
    string new_line;
    new_line.append(line_len, '_');
    for (int i = row; i < (unsigned long) row + text.size(); ++i) {
        if (new_page) {
            this->page.insert({i, new_line});
        } else {
            if (this->page.find(i) == this->page.end()) {
                this->page.insert({i, new_line});
            } else {
                if (this->page.at(i).at((unsigned long) col) != '_') {
                    return false;
                }
            }
        }

    }
    unsigned long j = 0;
    for (int i = row; i < (unsigned long) row + text.size(); ++i) {
        this->page.at(i).at((unsigned long) col) = text.at(j++);
    }
    return true;
}

void Page::row_erase(int row, int col, int len, bool new_page) {
    string new_line;
    new_line.append(line_len, '_');
    if (new_page) {
        this->page.insert({row, new_line});
    } else {
        if (this->page.find(row) == this->page.end()) {
            this->page.insert({row, new_line});
        }

    }
    for (int i = col; i < col + len; ++i) {
        this->page.at(row).at((unsigned long) i) = '~';
    }
}

void Page::col_erase(int row, int col, int len, bool new_page) {
    string new_line;
    new_line.append(line_len, '_');
    for (int i = row; i < row + len; ++i) {
        if (new_page) {
            this->page.insert({i, new_line});
        } else {
            if (this->page.find(i) == this->page.end()) {
                this->page.insert({i, new_line});
            }
        }

    }
    for (int i = row; i < row + len; ++i) {
        this->page.at(i).at((unsigned long) col) = '~';
    }
}