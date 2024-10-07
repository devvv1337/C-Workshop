#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

#include "ciutils/ciutils.hh"

int main(int argc, char* argv[])
{
    if (argc != 2)
        return 1;

    CIUtils::CIData res = CIUtils::parse_ci_file(argv[1]);
    std::cout << "stages(" << res.stages.size() << "):\n";
    for (size_t i = 0; i < res.stages.size(); i++)
    {
        std::cout << "  ";
        std::cout << res.stages[i] << '\n';
    }
    std::cout << '\n';
    std::cout << "jobs(" << res.jobs.size() << "):\n";
    for (size_t i = 0; i < res.jobs.size(); i++)
    {
        std::cout << "  ";
        std::cout << res.jobs[i].name << " (" << res.jobs[i].stage << ")\n";
    }
    std::cout << '\n';
    std::cout << "commands(" << res.commands.size() << "):\n";
    for (auto it = res.commands.begin(); it != res.commands.end(); it++)
    {
        std::cout << "  ";
        std::cout << *it << '\n';
    }
    return 0;
}