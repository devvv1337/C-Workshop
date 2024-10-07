#include "merge-sort.hh"

#include <algorithm>
#include <vector>

void merge_sort(iterator_type begin, iterator_type end)
{
    if (std::distance(begin, end) <= 1)
    {
        return;
    }
    auto mid = std::next(begin, std::distance(begin, end) / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);
    std::inplace_merge(begin, mid, end);
}
