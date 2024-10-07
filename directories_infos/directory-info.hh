#pragma once

#include <string>

struct DirectoryInfo
{
    std::string name_;
    unsigned int size_;
    unsigned int rights_;
    std::string owner_;

    DirectoryInfo() = default;
};
