#pragma once
#include "exist.hh"

template <class T>
bool Exist<T>::operator()(const T& val)
{
    if (value.count(val) > 0)
    {
        return true;
    }
    else
    {
        value.insert(val);
        return false;
    }
}