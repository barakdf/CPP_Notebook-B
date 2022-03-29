/**
 * Name = <Barak Dafna>, ID = <206795841>
 * */

#include <iostream>
#include <unordered_map>
#include "Notebook.hpp"
#include "Page.hpp"
#include <exception>
#include <string>

using namespace std;

using namespace ariel;
#define ERASED '~'

ariel::Notebook::~Notebook() {
    auto it = this->notebook.begin();
    while (it != this->notebook.end()) {
        cout << it->first << "::" << it->second << endl;
        free(it->second);
        it++;
    }
}

string ariel::Notebook::read(int page, int row, int collum, ariel::Direction direction, int len) {
    /* check all the illegal inputs */
    if (page < 0 || row < 0 || collum < 0 || collum > 99 || len < 1 ||
        (direction == ariel::Direction::Horizontal && (collum + len > 100))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    std::string ans;
    auto new_len = (unsigned long) (len - 1);
    auto new_col = (unsigned long) collum;
    /* in case when we didn't init the requested page yet.
     * we can return blank page as default. */
    if (this->notebook.find(page) == this->notebook.end()) {
        ans.append(new_len + 1, '_');
        return ans;
    }
    /* we will approach each direction differently */

    switch (direction) {
        /*
         * if the direction is Horizontal we will check if the specific row exists
         * if false: return simple '_' string.
         * if true: we will read the requested space in the row
         * */
        case ariel::Direction::Horizontal:
            if (this->notebook.at(page)->page.find(row) == this->notebook.at(page)->page.end()) {
                cout << "HERE" << endl;
                ans.append(new_len + 1, '_');
                return ans;
            }
//            ans = this->notebook.at(page)->page.at(row).substr((std::size_t) collum, new_len + new_col);
            for (int i = collum; i < collum + len; ++i) {
                ans += this->notebook.at(page)->page.at(row).at((unsigned long) i);
            }
            return ans;
            break;
            /*
             * if the direction is vertical we will iterate the rows at the specific collum
             * and check the existence of every row individual
             * if the specific row is missing, we simply add '_' to the string.
             * */
        case ariel::Direction::Vertical:
            for (int i = row; i < row + len; ++i) {
                if (this->notebook.at(page)->page.find(i) == notebook.at(i)->page.end()) {
                    ans += '_';
                } else {
                    ans += this->notebook.at(page)->page.at(i).at((unsigned long) i);
                }
            }
            return ans;
            break;
    }
}


void ariel::Notebook::write(int page, int row, int collum, ariel::Direction direction, const string &text) {
    /* check all the illegal inputs */
    if (page < 0 || row < 0 || collum < 0 || collum > 99 ||
        (direction == ariel::Direction::Horizontal && ((unsigned long) collum + text.size() > 100))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    bool init_page = false;
    if (notebook.find(page) == notebook.end()) {
        notebook.insert({page, new page::Page});
        init_page = true;
    }
    switch (direction) {
        case ariel::Direction::Horizontal:
            if (!this->notebook.at(page)->row_write(row, collum, text, init_page)) {
                throw invalid_argument("You cant write here!");
            }
            break;
        case ariel::Direction::Vertical:
            if (!this->notebook.at(page)->col_write(row, collum, text, init_page)) {
                throw invalid_argument("You cant write here!");
            }
            break;
    }
}


void ariel::Notebook::erase(int page, int row, int collum, ariel::Direction direction, int len) {
    if (page < 0 || row < 0 || collum < 0 || collum > 99 || len < 1 ||
        (direction == ariel::Direction::Horizontal && (collum + len > 100))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    bool init_page = false;
    if (notebook.find(page) == notebook.end()) {
        notebook.insert({page, new page::Page});
        init_page = true;
    }
    switch (direction) {
        case ariel::Direction::Horizontal:
            this->notebook.at(page)->row_erase(row, collum, len, init_page);
            break;
        case ariel::Direction::Vertical:
            this->notebook.at(page)->col_erase(row, collum, len, init_page);
            break;
    }

}

string ariel::Notebook::show(int page) {
    return "";
}

//int main() {
////    unordered_map<int, page::Page*> m;
////    auto *test = new page::Page;
////    test->page.insert({0,"HI"});
////    m.insert({0,test});
////
////    auto *test2 = new page::Page;
////    test2->page.insert({0,"HI"});
////    m.insert({3,test2});
//
//
//
////    cout<<m.at(0)->page.at(0)<<endl;
////    free(test);
////    free(test2);
//
////    Notebook note;
////
//////    note.write(0,0,1,Direction::Vertical,"OrelZamler");
//////    note.write(500,0,1,Direction::Vertical,"OrelZamler");
//////    note.write(1,0,0,Direction::Horizontal,"n____n");
//////    cout<<note.read(0,2,0,Direction::Horizontal ,9) <<endl;
//////    cout<<note.read(0,2,11,Direction::Horizontal ,9) <<endl;
//////    for (size_t row = 1; row < 13; row++){
//////        for (size_t col = 0; col < 100; col++){
//////            if (col == 0){
//////                cout<<note.read(0,row,0,Direction::Horizontal ,9) <<endl;
//////                col += 10;
//////            }else if (row < 12){
//////                cout << "row" << row << "col" << col <<endl;
//////                cout << note.read(0,row,col,Direction::Horizontal ,1)<< endl;
//////            }
//////        }
//////    }
//////    string str;
//////    str.append(1,'_');
//////    cout<<str<<endl;
////    for (int i = 0; i < 96; i++) {
////        note.write(1, i, i, Direction::Horizontal, "abcd");
////    }
////
////    for (int i = 1; i < 96; i++) {
////        cout << "attempt " << i << endl;
////        note.write(1, i - 1, i, Direction::Vertical, "ab");
//////        note.write(1,i-1,i,Direction::Vertical,"ab");
////    }
//
//    string test = " ";
//    if (test.at(0) == ' ')
//        cout << test.at(0) << endl;
//    else {
//        cout << "NO" << endl;
//    }
//
//
//}
