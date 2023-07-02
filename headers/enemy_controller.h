#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "../lib/thread.h"
#include "../lib/traits.h"
#include "./ship.h"
#include "./enemy_ship.h"
#include <list>

__BEGIN_API

class EnemyController
{
private:
    int _number_of_enemies = 4;
    float _enemy_speed = 100.f;
    static std::list<Thread *> _enemy_threads;
    static std::list<EnemyShip *> _enemy_ships;

    static int _alive_enemy_count;

public:
    EnemyController();
    ~EnemyController();
    static std::list<EnemyShip *> getEnemies();
};

__END_API

#endif