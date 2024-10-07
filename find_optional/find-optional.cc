#include "find-optional.hh"

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    size_t n = vect.size();
    for (std::size_t i = 0; i < n; ++i)
    {
        if (vect[i] == value)
        {
            return i;
        }
    }
    return std::nullopt;
}
