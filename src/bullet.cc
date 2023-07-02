#include "../headers/bullet.h"

__BEGIN_API

void Bullet::move(float delta, Direction direction, const std::string &path) {
    std::tuple<int, int> temp = get_position();
    int x = std::get<0>(temp);
    int y = std::get<1>(temp);
    set_direction(direction, path);
    // float delta = ClockCounter::get_time();
    //float delta = deltaVar;
    switch (direction)
    {
    case LEFT:
        if (x > 10+get_object_speed()) {
            x -= get_object_speed();
        } else {
            std::cout << "delete";
            delete this;
        }
        break;
    case RIGHT:
        if (x < (367*1.43)-get_object_speed()) {
            x += get_object_speed();
        } else {
            std::cout << "delete";
            delete this;
        }
        break;
    case UP:
        if (y > 10+get_object_speed()) {
            y -= get_object_speed();
        } else {
            std::cout << "delete";
            delete this;
        }
        break;
    case DOWN:
        if (y < (367*1.37)-get_object_speed()) {
            y += get_object_speed();
        } else {
            std::cout << "delete";
            delete this;
        }
        break;
    default:
        std::cout << "DEFAULT";
        x += 0;
        y += 0;
    }
    set_position(x, y);
}

Bullet::~Bullet() {
}

__END_API