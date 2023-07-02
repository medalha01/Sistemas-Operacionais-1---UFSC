#include "../headers/moving_object.h"
#include "../headers/game_object.h"
#include <tuple>
#include <iostream>
// #include "../headers/clock_counter.h"
__BEGIN_API

void MovingObject::move(float deltaVar, Direction direction, const std::string &path)
{
    
    std::tuple<int, int> temp = get_position();
    int x = std::get<0>(temp);
    int y = std::get<1>(temp);
    set_direction(direction, path);
    // float delta = ClockCounter::get_time();
    float delta = deltaVar;
    switch (direction)
    {
    case LEFT:
        if (x >= 10+_object_speed) {
            x -= _object_speed;
        }
        break;
    case RIGHT:
        if (x <= (367*1.43)-_object_speed) {
            x += _object_speed;
        }
        break;
    case UP:
        if (y >= 10+_object_speed) {
            y -= _object_speed;
        }
        break;
    case DOWN:
        if (y <= (367*1.37)-_object_speed) {
            y += _object_speed;
        }
        break;
    default:
        x += 0;
        y += 0;
    }
    set_position(x, y);

    // TODO CALCULO DE BOUNDS
}

float MovingObject::get_object_speed() {
    return _object_speed;
}

MovingObject::~MovingObject() {
}

/*
sf::FloatRect bounds = A::getGlobalBounds();
if (x_position < 0.f) setPosition(0.f, y_position);
else if (y_position < 0.f) setPosition(x_position, 0.f);
// TODO ARRUMAR ISSO AQUI
else if (x_position + bounds.width > 1086 - 320) _sprite.setPosition(1086 - 320 - bounds.width, y_position);
else if (y_position + bounds.height > 746 + 260) _sprite.setPosition(x_position, 746 + 260 - bounds.height);
else{
    _sprite.move(_movement);
*/

__END_API