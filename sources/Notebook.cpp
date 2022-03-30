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
/**
 * store all the common const values.
 * */
constexpr int line_len = 100;
constexpr int max_col = 99;
constexpr int min_space = 0;
constexpr int max_char_val = 125, min_char_val = 32;


/**
 * common function to check if the inputs is legal.
 * case false - throw "invalid Argument".
 * */
void illegal_inputs_read_erase(int page, int row, int col, Direction direction, int len) {
    if (page < min_space || row < min_space || col < min_space || col > max_col || len < 1 ||
        (direction == ariel::Direction::Horizontal && (col + len > line_len))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
}

/**
 * function to check if the text we try to write is contain illegal characters.
 * case false - throw Invalid Argument.
 * */
void check_printable(const string& text) {
    for (char i : text) {
        if (i < min_char_val || i > max_char_val) {
            throw invalid_argument("Invalid Character!");
        }
    }
}


/**
 * distructor for Notebook object,
 * each page has Infinite possible rows, so they allocate in heap memory.
 * we use the distructor to free all the allocated memory when the program ends.
 * */
ariel::Notebook::~Notebook() {
    auto it = this->notebook.begin();
    while (it != this->notebook.end()) {
        cout << it->first << "::" << it->second << endl;
        delete it->second;
        it++;
    }
}

string ariel::Notebook::read(int page, int row, int collum, ariel::Direction direction, int len) {
    /* check all the illegal inputs */
    illegal_inputs_read_erase(page,row,collum,direction,len);
    std::string ans;
    auto new_len = (unsigned long) (len - 1);
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
            for (int i = collum; i < collum + len; ++i) {
                ans += this->notebook.at(page)->page.at(row).at((unsigned long) i);
            }
            return ans;
            /*
             * if the direction is vertical we will iterate the rows at the specific collum
             * and check the existence of every row individual
             * if the specific row is missing, we simply add '_' to the string.
             * */
        case ariel::Direction::Vertical:
            for (int i = row; i < row + len; ++i) {
                if (this->notebook.at(page)->page.find(i) == notebook.at(page)->page.end()) {
                    ans += '_';
                } else {
                    ans += this->notebook.at(page)->page.at(i).at((unsigned long) collum);
                }
            }
            return ans;
    }
}


void ariel::Notebook::write(int page, int row, int collum, ariel::Direction direction, const string &text) {
    /* check all the illegal inputs */
    if (page < min_space || row < min_space || collum < min_space || collum > max_col ||
        (direction == ariel::Direction::Horizontal && ((unsigned long) collum + text.size() > line_len))) {
        throw std::invalid_argument("Invalid position in the notebook");
    }
    /**
     * check if the text contains illegal characters.
     * for example: erase char ('~') is not allowed in writing
     * */
    check_printable(text);
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
    illegal_inputs_read_erase(page,row,collum,direction,len);
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
    if (page < 0) {
        throw invalid_argument("Page must be positive!");
    }
    if (notebook.find(page) == notebook.end()) {
        notebook.insert({page, new page::Page});
        string new_line;
        new_line.append(line_len,'_');
        notebook.at(page)->page.insert({0,new_line});
    }
    string show_page = "   ";
    string title = " page " + std::to_string(page) + " ";
    show_page.append((line_len-title.size())/2, '=');
    show_page.append(title);
    show_page.append((line_len-title.size())/2, '=');
    show_page += '\n';
    int max_used_row = this->notebook.at(page)->page.begin()->first;
    for (int i = 0; i <= max_used_row ; ++i) {
        show_page.append(std::to_string(i)+": ");
        if (this->notebook.at(page)->page.find(i) == notebook.at(page)->page.end()) {
            show_page.append(line_len, '_');
        } else {
            show_page.append(this->notebook.at(page)->page.at(i));
        }
        show_page += "\n";
    }
    return show_page;
}






//int main() {
//    Notebook m;
//    auto *test = new page::Page;
//    m.write(4,0,0,Direction::Horizontal,"HI");
//    m.write(4,5,0,Direction::Vertical,"Hello");
//    m.erase(4,5,3,Direction::Horizontal,4);
//
////    auto *test2 = new page::Page;
////    test->page.insert({6,"HI"});
////    test->page.insert({9,"HI"});
////    m.notebook.insert({0,test2});
//
//
//
////    cout<<m.notebook.at(0)->page.begin()->first<<endl;
//    cout<< m.show(4)<<endl;
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
////    string test = " ";
////    if (test.at(0) == ' ')
////        cout << test.at(0) << endl;
////    else {
////        cout << "NO" << endl;
////    }
////    note.write(1, 6, 0, Direction::Horizontal, "hello_hello");
////    cout<<note.read(1,6,5,Direction::Horizontal,1)<<endl;
////    note.write(1,6,5,Direction::Horizontal, "^");
////    cout<<note.read(1,6,5,Direction::Horizontal,1)<<endl;
////    note.write(1,7,5,Direction::Vertical,"ABCD");
////    cout<<note.read(1,7,5,Direction::Vertical,4)<< endl;
////    string s = "";
////    for (size_t i = 0; i < 255; i++) {
////        char c = i;
////        s += c;
////    }
////    cout << s <<endl;
////
////    note.write(0,0,10,Direction::Vertical,"vertical test");
////    cout<<note.read(0, 0, 10, Direction::Vertical, 13)<<endl;
//
//}
