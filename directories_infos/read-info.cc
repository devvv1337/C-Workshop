#include "read-info.hh"

#include <sstream>

bool read_info(std::istream& in, DirectoryInfo& dir_info)
{
    std::string line;

    if (!std::getline(in, line))
        return false;

    std::istringstream Converted(line);

    if ((Converted >> dir_info.name_ >> dir_info.size_ >> std::oct
         >> dir_info.rights_ >> dir_info.owner_))
    {
        if (Converted >> dir_info.owner_)
            return false;
        return true;
    }
    return false;
}