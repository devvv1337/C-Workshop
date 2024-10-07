#include "int-container.hh"

MyIntContainer::MyIntContainer(size_t size)
    : current_size_{ 0 }
    , max_size_{ size }
    , elems_{ std::make_unique<int[]>(5000) }
{}

void MyIntContainer::print() const
{
    for (size_t i = 0; i < current_size_ - 1; ++i)
    {
        std::cout << elems_[i] << " | ";
    }
    std::cout << elems_[current_size_ - 1] << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ >= max_size_)
        return false;

    elems_[current_size_] = elem;
    ++current_size_;
    return true;
}
std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; ++i)
    {
        if (elems_[i] == elem)
            return i;
    }
    return std::nullopt;
}
std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return std::nullopt;

    --current_size_;
    return elems_[current_size_];
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
        return std::nullopt;

    return elems_[position];
}

void MyIntContainer::sort()
{
    for (size_t i = 1; i < current_size_; ++i)
    {
        int ff = elems_.get()[i];
        int j = i - 1;
        while (j >= 0 && elems_.get()[j] > ff)
        {
            elems_.get()[j + 1] = elems_.get()[j];
            j--;
        }
        elems_.get()[j + 1] = ff;
    }
}

bool MyIntContainer::is_sorted() const
{
    if (current_size_ == 0)
        return true;
    for (size_t i = 0; i <= current_size_ - 2; ++i)
    {
        if (elems_.get()[i] > elems_.get()[i + 1])
            return false;
    }
    return true;
}
