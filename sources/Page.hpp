#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

namespace page {
    class Page {
    public:
        std::unordered_map<int, std::string> page;

    };
}