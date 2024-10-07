#pragma once
#include "nft.hh"

inline NFT create_empty_nft()
{
    return nullptr;
}

inline NFT create_nft(const std::string& name)
{
    return std::make_unique<std::string>(name);
}
