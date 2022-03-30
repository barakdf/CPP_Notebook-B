#include <unordered_map>
#include "Page.hpp"

using namespace std;

using namespace page;
/**
 * determine new line in the notebook to be string of char '_' in length of 100.
 * used when need to make new row, relevant for all 4 the functions below.*/
static const int line_len = 100;



/**
 * this function writes the text in Horizontal direction in the notebook.
 * if the requested row does not exists, it will make a new one and then write.
 * if the row exists, the function will check if there is not already written or erased chars in the row.
 * if can't write, return false, else true.*/
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
    unsigned long j = 0;
    for (int i = col; i < (unsigned long)col + text.size(); ++i) {
        this->page.at(row).at((unsigned long) i) = text.at(j++);
    }
    return true;
}
/**
 * this function writes the text in Vertical direction in the notebook.
 * the function will iterate over the rows and in every row will check:
 * - if the row does not exist -> will make a new one and right the right char from the text.
 * - if the row exist, will check if there is not already char or '~'(erased symbol), and then write the char.
 * if can't write, return false, else true.*/
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
/**
 * this function erase the space in the notebook in Horizontal direction.
 * if no line is exists, make a new one, and then erase the requested space.*/
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
/** this function erase the space in the notebook in Vertical direction.
 * if no line is exists, make a new one, and then erase the requested space.*/
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