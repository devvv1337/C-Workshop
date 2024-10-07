#include "auction.hh"

#include <algorithm>
#include <utility>
#include <vector>

#include "auction.hh"
#include "nft.hh"
#include "person.hh"

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , nft_(std::move(nft))
    , highest_bidder_(nullptr)
    , highest_bid_(initial_bid)
{}

bool Auction::bid(Person& person, uint money)
{
    if (money > highest_bid_)
    {
        if (person.remove_money(money))
        {
            if (highest_bidder_)
            {
                highest_bidder_->add_money(highest_bid_);
            }
            highest_bidder_ = &person;
            highest_bid_ = money;
            return true;
        }
    }
    else
    {
        return false;
    }
    return true;
}

std::string Auction::get_nft_name() const
{
    return nft_->c_str();
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}

Auction::~Auction()
{
    if (highest_bidder_)
    {
        organizer_.add_money(highest_bid_);
        organizer_.remove_nft(nft_->c_str());
        highest_bidder_->add_nft(std::move(nft_));
    }
    else
    {
        organizer_.add_nft(std::move(nft_));
    }
}