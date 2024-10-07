#include <iostream>
#include <string>

#include "implements.hh"

int main()
{
    std::cout << std::boolalpha;
    std::cout << impl_basic_op<int> << '\n';
    std::cout << impl_basic_op<int, float> << '\n';
    std::cout << impl_basic_op<std::string> << '\n';
}