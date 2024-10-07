#include <fstream>
#include <iostream>
#include <string>

ssize_t word_count(const std::string& filename)
{
    std::ifstream Myfile(filename);
    if (!Myfile)
        return -1;
    std::string line;
    int c = 0;
    while (Myfile >> line)
        c++;

    return c;
}
