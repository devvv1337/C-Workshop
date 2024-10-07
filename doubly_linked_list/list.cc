#include "list.hh"

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    if (!nb_elts_)
    {
        auto node = std::make_shared<Node>(i);
        first_ = last_ = node;
        nb_elts_++;
    }
    else
    {
        auto node = std::make_shared<Node>(i);
        node->next_set(first_);
        first_->prev_set(node);
        first_ = node;
        nb_elts_++;
    }
}

void List::push_back(int i)
{
    if (!nb_elts_)
    {
        auto node = std::make_shared<Node>(i);
        first_ = node;
        last_ = node;
        nb_elts_++;
    }
    else
    {
        auto node = std::make_shared<Node>(i);
        node->prev_set(last_);
        last_->next_set(node);
        last_ = node;
        nb_elts_++;
    }
}

std::optional<int> List::pop_front()
{
    if (!nb_elts_)
    {
        return std::nullopt;
    }
    else if (nb_elts_ == 1)
    {
        auto node = first_;
        first_ = first_->next_get();
        nb_elts_ = 0;
        return node->val_get();
    }
    else
    {
        auto node = first_;
        first_ = node->next_get();
        first_->prev_set(nullptr);
        nb_elts_--;
        return node->val_get();
    }
    return 0;
}

std::optional<int> List::pop_back()
{
    if (!nb_elts_)
    {
        return std::nullopt;
    }
    else if (nb_elts_ == 1)
    {
        auto node = first_;
        first_ = first_->next_get();
        nb_elts_ = 0;
        return node->val_get();
    }
    else
    {
        auto node = last_;
        last_ = node->prev_get();
        last_->next_set(nullptr);
        nb_elts_--;
        return node->val_get();
    }
    return 0;
}

void List::print(std::ostream& os) const
{
    if (!nb_elts_)
        return;

    auto node = first_;

    for (int i = 0; i <= nb_elts_ - 1; i++)
    {
        if (i <= nb_elts_ - 2)
            os << node.get()->val_get() << ' ';
        else
        {
            os << node.get()->val_get();
        }

        node = node->next_get();
    }
}

int List::length() const
{
    return nb_elts_;
}
