#include "engine.hh"

Engine::Engine(int fuel)
    : fuel_(fuel)
{}

bool Engine::start()
{
    if (fuel_ > 0)
    {
        std::cout << "Engine starts with " << --fuel_ << " units of fuel"
                  << std::endl;
        return true;
    }
    return false;
}

void Engine::use(int consumed)
{
    if (consumed > fuel_)
        consumed = fuel_;
    std::cout << "Engine uses " << consumed << " fuel units" << std::endl;
    fuel_ -= consumed;
}

void Engine::stop() const
{
    std::cout << "Stop Engine" << std::endl;
}

void Engine::fill(int fuel)
{
    fuel_ += fuel;
    std::cout << "Engine now has " << fuel_ << " fuel units" << std::endl;
}
