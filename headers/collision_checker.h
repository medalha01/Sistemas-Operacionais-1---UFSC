#ifndef collision_checker_h
#define collision_checker_h

#include <png.h>
#include <SFML/Graphics.hpp>
#include "../lib/thread.h"
#include "../headers/game_object.h"
#include "../headers/player.h"
#include "../headers/enemy_ship.h"
#include "../headers/enemy_controller.h"

__BEGIN_API

class CollisionChecker
{

public:
    CollisionChecker();
    ~CollisionChecker();
    static void run();
    static bool check_collision(GameObject * obj1, GameObject * obj2);
protected:

};

__END_API

#endif