#pragma once

template <class Range, class Fonction>
int my_foreach(Range start, Range end, Fonction f)
{
    while (start != end)
    {
        f(*start);
        start++;
    }
    return 0;
}
