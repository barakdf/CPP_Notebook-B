#pragma once
#include <iostream>
#include "Direction.hpp"
#include "Page.hpp"

using namespace std;
namespace ariel {
    class Notebook{
    private:
        unordered_map<int, page::Page*> notebook;

    public:

        string read(int page, int row, int collum, Direction direction, int len);

        void write(int page, int row, int collum, Direction direction, const string &text);

        void erase(int page, int row, int collum, Direction direction, int len);

        string show(int page);
    };
}