#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream myFile(input_filename);
    std::ofstream out(output_filename);
    if (!myFile)
    {
        std::cerr << "Cannot open input file" << std::endl;
        return;
    }

    if (!out)
    {
        std::cerr << "Cannot write output file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(myFile, line))
    {
        std::string lineModified;
        std::size_t pos = 0;
        std::size_t n = line.length();
        while (pos < n)
        {
            std::size_t hit = line.find(src_token, pos);
            if (hit == std::string::npos)
            {
                lineModified += line.substr(pos);
                break;
            }
            else
            {
                lineModified += line.substr(pos, hit - pos);
                lineModified += dst_token;
                pos = hit + src_token.length();
            }
        }
        out << lineModified << std::endl;
    }
}