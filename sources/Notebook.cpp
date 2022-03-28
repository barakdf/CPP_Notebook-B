/**
 * Name = <Barak Dafna>, ID = <206795841>
 * */

#include <iostream>
#include <unordered_map>
#include "Notebook.hpp"
#include "Page.hpp"
#include <exception>

using namespace std;

using namespace ariel;
#define ERASED '~'


string ariel::Notebook::read(int page, int row, int collum, ariel::Direction direction, int len) {
    if (page < 0 || row < 0 || collum < 0 || collum > 99 || len < 1 ||
        (direction == ariel::Direction::Horizontal && (collum + len > 99))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    string ans;
    /* in case when we didn't init the requested page yet.
     * we can return blank page as default. */
    if (notebook.find(page) == notebook.end()) {

        ans.append((unsigned long) len, '_');
        return ans;
    }

    /* we will approach each direction differently */
    auto new_len = (unsigned long) (len - 1);
    auto new_col = (unsigned long) collum;
    switch (direction) {
        case ariel::Direction::Horizontal:
            if (notebook.at(page)->page.find(row) == notebook.at(page)->page.end()) {
                ans.append((unsigned long) len, '_');
                return ans;
            }
            ans += notebook.at(page)->page.at(row).substr((std::size_t) collum, new_len + new_col);
            return ans;

        case ariel::Direction::Vertical:
            for (int i = row; i < len; ++i) {
                if (notebook.at(page)->page.find(i) == notebook.at(i)->page.end()) {
                    ans += '_';
                } else {
                    ans += notebook.at(page)->page.at(i).at((unsigned long) i);
                }
            }
            return ans;
    }
}


void ariel::Notebook::write(int page, int row, int collum, ariel::Direction direction, const string &text) {
    if (page < 0 || row < 0 || collum < 0 || collum > 99 ||
        (direction == ariel::Direction::Horizontal && ((unsigned long) collum + text.size() > 99))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    bool init_page = false;
    if (notebook.find(page) == notebook.end()) {
        notebook.insert({page,new page::Page});
        init_page = true;
    }
    switch (direction) {
        case ariel::Direction::Horizontal:
            notebook.at(page)->row_write(row, collum, text, init_page);
        case ariel::Direction::Vertical:
            notebook.at(page)->col_write(row, collum, text, init_page);
    }
}


void ariel::Notebook::erase(int page, int row, int collum, ariel::Direction direction, int len) {
    if (page < 0 || row < 0 || collum < 0 || collum > 99 || len < 1 ||
        (direction == ariel::Direction::Horizontal && (collum + len > 99))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }

}

string ariel::Notebook::show(int page) {
    return "";
}
