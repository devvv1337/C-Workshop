#pragma once
#include <cassert>

#include "shared-pointer.hh"

template <typename T>
SharedPointer<T>::SharedPointer(T* p)
    : data_(p)
    , count_(new long(1))
{}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    (*count_)--;
    if (*count_ == 0)
    {
        delete data_;
        delete count_;
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other)
    : data_(other.data_)
    , count_(other.count_)
{
    if (count_)
        (*count_)++;
}

template <typename T>
void SharedPointer<T>::reset(T* p)
{
    if (data_ == p)
        return;
    (*count_)--;
    if ((*count_) == 0)
    {
        delete data_;
    }

    data_ = p;
    count_ = new long(1);
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& other)
{
    if (this != &other)
    {
        if (count_)
        {
            (*count_)--;
            if (*count_ == 0)
            {
                delete data_;
                delete count_;
            }
        }
        data_ = other.data_;
        count_ = other.count_;
        if (count_)
        {
            (*count_)++;
        }
    }
    return *this;
}
template <typename T>
T& SharedPointer<T>::operator*() const
{
    if (data_ != nullptr)
        return *data_;
    else
        throw std::runtime_error("err");
}

template <typename T>
T* SharedPointer<T>::operator->() const
{
    if (data_ != nullptr)
        return data_;
    else
        throw std::runtime_error("err");
}

template <typename T>
template <typename U>
bool SharedPointer<T>::operator==(const SharedPointer<U>& rhs) const
{
    return data_ == rhs.data_;
}

template <typename T>
template <typename U>
bool SharedPointer<T>::operator!=(const SharedPointer<U>& rhs) const
{
    return data_ != rhs.data_;
}

template <typename T>
bool SharedPointer<T>::operator==(const T* p) const
{
    return data_ == p;
}

template <typename T>
bool SharedPointer<T>::operator!=(const T* p) const
{
    return data_ != p;
}

template <typename T>
SharedPointer<T>::operator bool() const
{
    return !(data_ == nullptr);
}

template <typename T>
template <typename U>
bool SharedPointer<T>::is_a() const
{
    return dynamic_cast<U*>(data_) != nullptr;
}