#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "../lib/traits.h"
#include <png.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

__BEGIN_API

class GameObject
{


public:
    enum Direction
    {
        RIGHT,
        LEFT,
        UP,
        DOWN
    };
    GameObject(float scale, Direction objectDirection, int x, int y, const std::string &path);
    ~GameObject();

    sf::Texture *load_texture(const std::string &path);
    sf::Sprite *get_sprite();
    sf::Texture *get_texture();
    float get_scale();
    void set_position(int x, int y);
    void set_direction(Direction objectDirection, const std::string &path);
    std::tuple<int, int> get_position();
    
    sf::Sprite *update_sprite();
    GameObject::Direction get_direction();

private:
    Direction _objectDirection;
    float _scale;
    std::tuple<int, int> _position;
    int _alive;
    sf::Sprite _sprite;
    sf::Texture _texture;
};

__END_API

#endif