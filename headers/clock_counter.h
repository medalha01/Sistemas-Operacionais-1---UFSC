#ifndef CLOCK_COUNTER_H
#define CLOCK_COUNTER_H

#include <SFML/Graphics.hpp>
#include <list>
#include "../lib/thread.h"

__BEGIN_API

class ClockCounter
{
public:
    static float start();
    static void set_clock_time();
    static float get_time();

private:
    static sf::Clock deltaClock;
    static float delta;
};

__END_API

#endif