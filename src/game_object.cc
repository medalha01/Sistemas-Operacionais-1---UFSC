#include "../headers/game_object.h"
#include <iostream>
__BEGIN_API

sf::Texture *GameObject::load_texture(const std::string &path)
{
    _texture.loadFromFile(path);
    return &_texture;
}

sf::Sprite *GameObject::get_sprite()
{
    return &_sprite;
}

GameObject::GameObject(float scale, Direction objectDirection, int x, int y, const std::string &path)
{
    GameObject::load_texture(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    _sprite.scale(scale, scale);
    //_sprite.rotate(90); change with direction
    _objectDirection = objectDirection;
    _position = std::make_tuple(x, y);
    _scale = scale;
}

void GameObject::set_position(int x, int y)
{
    _sprite.setPosition(x, y);
    _position = std::make_tuple(x, y);
}

void GameObject::set_direction(Direction objectDirection, const std::string &path)
{   
    GameObject::load_texture(path);
    _objectDirection = objectDirection;
    switch (objectDirection)
    {
    case RIGHT:
        _sprite.setTexture(_texture);
        break;
    case LEFT:
        _sprite.setTexture(_texture);
        break;
    case UP:
        _sprite.setTexture(_texture);
        break;
    case DOWN:
        _sprite.setTexture(_texture);
        break;
    default:
        _sprite.setRotation(0);
    };
    //_sprite.rotate(90); change with direction
}

sf::Texture *GameObject::get_texture()
{
    return &_texture;
}

float GameObject::get_scale()
{
    return _scale;
}

std::tuple<int, int> GameObject::get_position()
{
    return _position;
}

sf::Sprite *GameObject::update_sprite()
{
    _sprite.setTexture(_texture);
    _sprite.setPosition(std::get<0>(_position), std::get<1>(_position));
    _sprite.scale(_scale, _scale);
    return &_sprite;
}

GameObject::Direction GameObject::get_direction()
{
    return _objectDirection;
}

GameObject::~GameObject() {
    
}

__END_API