#pragma once

#include "nft.hh"
#include "person.hh"

class Auction
{
public:
    Auction(Person& organizer, NFT nft, uint initial_bid);

    ~Auction();

    Auction(const Auction&&) = delete;
    Auction(const Auction&) = delete;
    Auction& operator=(const Auction&) = delete;

    bool bid(Person& person, uint money);

    std::string get_nft_name() const;
    uint get_highest_bid() const;

private:
    Person& organizer_;
    NFT nft_;
    Person* highest_bidder_;
    uint highest_bid_;
};
