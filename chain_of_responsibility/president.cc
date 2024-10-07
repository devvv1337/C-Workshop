#include "president.hh"

#include <iostream>

void President::handle_request(int level)
{
    if (level > 9)
        forward_request(level);
    else
        std::cout << "President handles" << std::endl;
}
