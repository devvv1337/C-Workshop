#pragma once

#include <memory>
#include <string>

using NFT = std::unique_ptr<std::string>;

NFT create_empty_nft();

NFT create_nft(const std::string& name);

#include "nft.hxx"
