#ifndef BULLET_H
#define BULLET_H

#include "../lib/thread.h"
#include "../lib/traits.h"
//#include "./ship.h"
#include "./moving_object.h"

__BEGIN_API


class Bullet : public MovingObject
{
    public:
    enum TYPE
    {
        FRIEND,
        ENEMY
    };
    private:
        TYPE _type;
    public:
    Bullet(float scale, Direction objectDirection, int x, int y, const std::string &path, float speed, TYPE shoot_type)
        : MovingObject(scale, objectDirection, x, y, path, speed){
            Bullet::_type = shoot_type;
        }

<<<<<<< HEAD

=======
public:
    Bullet();
    ~Bullet();
    using MovingObject::move;
    void move(float delta, Direction direction, const std::string &path);
>>>>>>> 74f6acc9530e9c8afa511b70894954d91922e3c2
};

__END_API

#endif