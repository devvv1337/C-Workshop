#pragma once

template <bool Cond, typename T = void>
struct enable_if
{};

template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};
