#include "../lib/thread.h"
#include "../headers/main_screen.h"

__BEGIN_API

GameObject* mainScreen::_maze;

mainScreen::mainScreen(std::string imagepath) {
    _maze = new GameObject(1.5, GameObject::Direction::UP, 0, 0, "sprites/maze/screen.png");
    sf::Text * liv = new sf::Text;
    liv->setString("3");
    sf::Text * score = new sf::Text;
    score->setString("0");
    sf::Text * vel = new sf::Text;
    vel->setString("1");
    sf::Text * alv = new sf::Text;
    alv->setString("4");
    sf::Text * name = new sf::Text;
    name->setString("JOGO");
    update(liv, score, vel, alv, name);
}

void mainScreen::update(sf::Text *  new_player_lives, sf::Text * new_score, sf::Text * new_velocity, sf::Text * new_enemies_alive, sf::Text * new_game_name) {
    player_lives = new_player_lives;
    score = new_score;
    velocity = new_velocity;
    enemies_alive = new_enemies_alive;
    game_name = new_game_name;
}

void mainScreen::setFont(sf::Font newfont) {
    font = &newfont;
}

sf::Font* mainScreen::getFont() {
    return font;
}

GameObject * mainScreen::get_maze() {
    return _maze;
}

sf::Text* mainScreen::get_player_lives() {
    return player_lives;
}

sf::Text* mainScreen::get_score() {
    return score;
}

sf::Text* mainScreen::get_velocity() {
    return velocity;
}

sf::Text* mainScreen::get_name() {
    return game_name;
}

sf::Text* mainScreen::get_enemies_alive() {
    return enemies_alive;
}

sf::Sprite * mainScreen::getSprite() {
    return mainScreen::_maze->get_sprite();
}
__END_API