#include "player.hh"

#include <exception>
#include <iostream>
#include <string>

Player::Player(const std::string& name, unsigned int age)
    : name_(name)
    , age_(age)
{
    if (!name.length())
        throw InvalidArgumentException("Name can't be empty.");
    if (age > 150)
        throw InvalidArgumentException("Sorry gramp, too old to play.");
}
