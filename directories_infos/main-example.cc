#include <fstream>
#include <iomanip>
#include <iostream>

#include "directory-info.hh"
#include "read-info.hh"

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;

    auto file = std::ifstream(argv[1]);

    while (true)
    {
        auto dir_info = DirectoryInfo{};
        auto success = read_info(file, dir_info);

        if (!success)
            break;

        std::cout << dir_info.name_ << '|' << dir_info.size_ << '|' << std::oct
                  << dir_info.rights_ << std::dec << '|' << dir_info.owner_
                  << '\n';
    }
}
