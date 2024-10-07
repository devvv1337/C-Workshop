#include "director.hh"

#include <iostream>

void Director::handle_request(int level)
{
    if (level > 3)
        forward_request(level);
    else
        std::cout << "Director handles" << std::endl;
}
