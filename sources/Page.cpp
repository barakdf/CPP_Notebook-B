#include <iostream>
#include <unordered_map>
#include "Page.hpp"

using namespace std;

using namespace page;
void Page::row_write(int row, int col, const string &text, bool new_l) {
    string new_line;
    new_line.append(100, '_');
    if (new_l) {
        this->page.insert({row,new_line});
    } else {
        if (this->page.find(row) == this->page.end()) {
            this->page.insert({row,new_line});
        }
        if (this->page.at(row).substr((unsigned long )col,(unsigned long )col + text.size()).find('~') != std::string::npos) {
            throw invalid_argument("You cant write here!");
        }
    }
    this->page.at(row).replace((unsigned long )col, text.size(), text);
}
void Page::col_write(int row, int col, const std::string &text, bool new_page) {
    string new_line;
    new_line.append(100, '_');
    for (int i = row; i < text.size() ; ++i) {
        if (new_page) {
            this->page.at(i) = new_line;
        } else {
            if (this->page.find(i) == this->page.end()) {
                this->page.insert({i,new_line});
            } else {
                if (this->page.at(i).at((unsigned long) col) == '~') {
                    throw invalid_argument("You cant write here!");
                }
            }
        }

    }
    for (int i = row; i < text.size(); ++i) {
        unsigned long j = 0;
        this->page.at(i).at((unsigned long)col) = text.at(++j);
    }
}