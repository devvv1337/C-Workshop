#include "person.hh"

Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
{}

std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> nft_names;
    for (auto& nft : nfts_)
    {
        if (nft)
        {
            nft_names.push_back(*nft);
        }
    }
    return nft_names;
}

void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    for (auto& nft : nfts_)
    {
        if (nft)
        {
            if (*nft == name)
            {
                auto res = std::move(nft);
                return res;
            }
        }
    }
    return create_empty_nft();
}

void Person::add_money(uint money)
{
    money_ += money;
}

bool Person::remove_money(uint money)
{
    if (money_ >= money)
    {
        money_ -= money;
        return true;
    }
    else
    {
        return false;
    }
}

uint Person::get_money() const
{
    return money_;
}

std::string Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << "\nMoney: " << p.get_money() << "\nNFTs:";
    auto nft_names = p.enumerate_nfts();
    if (!nft_names.empty())
    {
        {
            for (auto& name : nft_names)
            {
                os << " " << name;
            }
        };
    }
    os << '\n';
    return os;
}