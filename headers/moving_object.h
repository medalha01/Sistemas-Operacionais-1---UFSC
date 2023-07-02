#ifndef MOVE_H
#define MOVE_H

#include "../lib/traits.h"
#include "game_object.h"
#include <tuple>

__BEGIN_API

class MovingObject : public GameObject
{
public:
    MovingObject(float scale, Direction objectDirection, int x, int y, const std::string &path, float speed)
        : GameObject(scale, objectDirection, x, y, path)
    {
        _object_speed = speed;
    };
    void move(float delta, Direction direction, const std::string &path);
    float get_object_speed();
    ~MovingObject();

private:
    float _object_speed;
};

__END_API

#endif