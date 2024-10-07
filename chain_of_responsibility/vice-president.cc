#include "vice-president.hh"

#include <iostream>

void VicePresident::handle_request(int level)
{
    if (level > 6)
        forward_request(level);
    else
        std::cout << "VicePresident handles" << std::endl;
}
