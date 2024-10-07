#pragma once
#include "bimap.hh"

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs[v1] = v2;
    rhs[v2] = v1;
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    lhs[v2] = v1;
    rhs[v1] = v2;
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    auto hit = lhs.find(v);
    if (hit != lhs.end())
    {
        rhs.erase(hit->second);
        lhs.erase(hit);
    }
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    auto hit = rhs.find(v);
    if (hit != rhs.end())
    {
        lhs.erase(hit->second);
        rhs.erase(hit);
    }
}

template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT1 Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT2 Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}

template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return lhs.size();
}

template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    lhs.clear();
    rhs.clear();
}
