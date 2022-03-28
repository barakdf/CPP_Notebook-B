#pragma once
#include <iostream>
#include "Direction.hpp"

using namespace std;
namespace ariel {
    class Notebook{
    public:

        static string read(int page, int row, int collum, Direction direction, int len);

        void write(int page, int row, int collum, Direction direction, const string &text);

        void erase(int page, int row, int collum, Direction direction, int len);

        static string show(int page);
    };
}