#include "address-book.hh"

AddressBook::AddressBook()
{}
bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.length())
    {
        try
        {
            book_.insert({ full_name, ContactDetails(number, email) });
            return true;
        }
        catch (const std::invalid_argument& a)
        {
            return false;
        }
    }
    return false;
}
std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> d;
    for (auto item : book_)
    {
        if (item.first == full_name)
        {
            d.push_back(item.second);
        }
    }
    return d;
}
std::size_t AddressBook::count(const std::string& full_name)
{
    int c = 0;

    for (auto item : book_)
    {
        if (item.first == full_name)
        {
            c++;
        }
    }
    return c;
}
bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    auto hit = book_.find(full_name);
    std::size_t count = 0;
    while (hit != book_.end() && hit->first == full_name)
    {
        if (count == index)
        {
            book_.erase(hit);
            return true;
        }
        ++hit;
        ++count;
    }
    return false;
}
void AddressBook::remove_all(const std::string& full_name)
{
    book_.erase(full_name);
}
std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.book_.size() << " contact(s) in the address book.\n";
    for (auto [name, details] : b.book_)
    {
        os << "- " << name << ": " << details.number << ", " << details.email
           << std::endl;
    }
    return os;
}
