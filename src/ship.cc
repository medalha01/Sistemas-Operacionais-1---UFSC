#include "../headers/ship.h"
#include "../headers/clock_counter.h"

__BEGIN_API



sf::Sprite *Ship::get_ship_sprite(Ship *calling_ship){
    return calling_ship->get_sprite();
}

std::tuple<int, int> Ship::get_ship_position(Ship *calling_ship){
    return calling_ship->get_position();
}

std::vector<Bullet *>* Ship::get_bullet_list(){
    return &_bullet_list;
}



/*void Ship::shoot(Ship *calling_ship){
    std::vector<Bullet *>* bullets = calling_ship->get_bullet_list();
    bullets->push_back(new Bullet());
}*/

void Ship::pop_bullet(Ship *calling_ship){
    std::vector<Bullet *>* bullets = calling_ship->get_bullet_list();
}

void Ship::shoot(){
    std::tuple<int, int> pos = get_position();
    _bullet_list.push_back(new Bullet(0.5, get_direction(), std::get<0>(pos)+18,std::get<1>(pos)+18, "sprites/space_ships/shot.png", 10.0, Bullet::TYPE::FRIEND));
}

/*void Ship::die(Ship *calling_ship){
    delete calling_ship;
}*/

__END_API

//    bool _ready_to_shoot;
//    bool _reload_time;
//    State _shipState;

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

    // BULLETS?}
