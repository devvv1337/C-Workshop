#pragma once

constexpr unsigned long long factorial(unsigned int n)
{
    unsigned long long res = 1;
    for (unsigned int i = 2; i <= n; ++i)
    {
        res *= i;
    }
    return res;
}