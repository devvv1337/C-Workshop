#include <iostream>

#include "find-optional.hh"

int main()
{
    auto const opt = find_optional({ 1, 2, 42, 3 }, 42);

    if (opt == 2)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    return 0;
}
