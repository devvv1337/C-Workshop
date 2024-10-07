#pragma once
#include <unordered_set>
template <class T>
class Exist
{
public:
    bool operator()(const T& v);

private:
    std::unordered_set<T> value;
};

#include "exist.hxx"