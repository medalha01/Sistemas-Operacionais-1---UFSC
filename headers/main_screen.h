#ifndef SCREEN_h
#define SCREEN_h

#include "game_object.h"
#include <SFML/Graphics.hpp>

__BEGIN_API

class mainScreen{
private:
    static GameObject* _maze;
    sf::Text* player_lives;
    sf::Text* score;
    sf::Text* velocity;
    sf::Text* game_name;
    sf::Text* enemies_alive;
    sf::Font* font;
public:
    mainScreen(std::string name);

    void update(sf::Text *  new_player_lives, sf::Text * new_score, sf::Text * new_velocity, sf::Text * new_enemies_alive, sf::Text *new_game_name);
    void setFont(sf::Font font);
    sf::Font* getFont();
    GameObject* get_maze();
    sf::Text* get_player_lives();
    sf::Text* get_score();
    sf::Text* get_velocity();
    sf::Text* get_name();
    sf::Text* get_enemies_alive();
    static sf::Sprite* getSprite();
};

__END_API
#endif