#ifndef SHIP_H
#define SHIP_H

#include <png.h>
#include <SFML/Graphics.hpp>
#include "moving_object.h"
#include "../lib/traits.h"
#include <tuple>
#include <list>
#include "bullet.h"

__BEGIN_API

class Ship : public MovingObject
{
public:
    Ship(float scale, Direction objectDirection, int x, int y, const std::string &path, float speed, float reload_time)
        : MovingObject(scale, objectDirection, x, y, path, speed)
    {
        Ship::_ready_to_shoot = true;
        Ship::_reload_time = reload_time;
        Ship::_bullet_list = std::vector<Bullet *>();
        Ship::_shipState = ALIVE;
    }
    //~Ship();

    static sf::Sprite *get_ship_sprite(Ship *calling_ship);
    static std::tuple<int, int> get_ship_position(Ship *calling_ship);
    static void update_bullets(Ship *calling_ship);
    std::vector<Bullet*> * get_bullet_list();
    static void pop_bullet(Ship *calling_ship);
    void shoot();
    //static void die(Ship *calling_ship);
protected:
    enum State
    {
        ALIVE,
        DEAD
    };

private:
    

    Thread *_ship_thread;
    bool _ready_to_shoot;
    bool _reload_time;
    State _shipState;
    std::vector<Bullet *> _bullet_list;
    

    // Texture and Sprite loaded on constructor
    /*State _state;
    int x_position;
    int y_position;
    sf::Texture* ship_texture;
    sf::Sprite* ship_sprite;
    Direction _direction;
    float _scale;
    float _speed;*/

    // float scale, int size, float speed, const std::map<Orientation, std::string>& paths, Orientation initial_orientation, Clock* clock, int x, int y

    // BULLETS?
};

__END_API

#endif