#pragma once

#include <ostream>
#include <vector>

#include "nft.hh"

class Person
{
public:
    Person(const std::string& name, uint money);

    std::vector<std::string> enumerate_nfts() const;

    void add_nft(NFT nft);
    NFT remove_nft(const std::string& name);

    void add_money(uint money);
    bool remove_money(uint money);

    uint get_money() const;
    std::string get_name() const;

private:
    std::string name_;
    uint money_;
    std::vector<NFT> nfts_;
};

std::ostream& operator<<(std::ostream& os, const Person& p);
