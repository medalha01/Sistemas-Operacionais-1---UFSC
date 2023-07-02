#ifndef ENEMY_SHIP_H
#define ENEMY_SHIP_H

#include "../lib/thread.h"
#include "../lib/traits.h"
#include "./ship.h"

__BEGIN_API

class EnemyShip : public Ship
{
public:
    enum Behavior
    {
        SUICIDAL,
        LONG_RANGE,
    };
    EnemyShip(float scale, Direction objectDirection, int x, int y, const std::string &path, float speed, float reload_time)
        : Ship(scale, objectDirection, x, y, path, speed, reload_time)
    {
    }
    ~EnemyShip();
    void EnemyShip::init();
    void EnemyShip::act(float dt);

private:
    Thread *_enemy_thread;
    Behavior _behavior;
    bool isAlive;
    void run();
};

__END_API

#endif