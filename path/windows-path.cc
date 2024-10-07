#include "windows-path.hh"

#include <array>
#include <iostream>
#include <string>
WindowsPath::WindowsPath(char drive)
{
    path_.push_back(drive + std::string(":"));
}

WindowsPath& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (!final_)
    {
        for (const char& c : tail)
        {
            if (c == ':' || c == '"' || c == '|' || c == '?' || c == '*')
            {
                return *this;
            }
        }
        path_.push_back(tail);

        if (is_file)
        {
            final_ = true;
        }
    }

    return *this;
}

std::string WindowsPath::to_string() const
{
    std::string result;
    result = path_[0];
    for (unsigned int i = 1; i < path_.size(); ++i)
    {
        result += '\\' + path_[i];
    }
    if (!final_)
    {
        result += '\\';
    }
    return result;
}
