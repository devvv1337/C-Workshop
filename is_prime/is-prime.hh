#pragma once
template <unsigned N>
constexpr bool is_prime()
{
    if (N == 0 || N == 1)
        return false;
    if (N == 2)
        return true;
    for (unsigned i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
