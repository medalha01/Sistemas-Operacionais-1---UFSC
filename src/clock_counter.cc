#include "../headers/clock_counter.h"

__BEGIN_API

sf::Clock ClockCounter::deltaClock;
float ClockCounter::delta;

float ClockCounter::start()
{
    return deltaClock.restart().asSeconds();
}

float ClockCounter::get_time()
{
    return deltaClock.getElapsedTime().asSeconds();
}

void ClockCounter::set_clock_time()
{
    delta = start();
}

__END_API