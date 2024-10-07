#include "stdin-to-file.hh"

#include <fstream>
#include <iostream>
#include <string>
void stdin_to_file()
{
    std::ofstream Myfile("file.out");

    std::string line;
    while (std::cin >> line)
        Myfile << line << std::endl;

    Myfile.close();
}