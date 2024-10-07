#include "unix-path.hh"

#include <array>
#include <iostream>
#include <string>
UnixPath& UnixPath::join(const std::string& tail, bool is_file)
{
    if (final_)
    {
        return *this;
    }
    if (path_.empty())
        path_.push_back('/' + tail);
    else
    {
        path_.push_back(tail);
    }
    if (is_file)
    {
        final_ = true;
    }
    return *this;
}

std::string UnixPath::to_string() const
{
    std::string res;
    res += '/';
    for (const auto& dir : path_)
    {
        res += dir + '/';
    }
    if (final_)
    {
        res.pop_back();
    }
    return res;
}