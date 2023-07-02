#include "../headers/player.h"
#include "../headers/game_object.h"
#include "../lib/thread.h"
#include "../headers/keyboard.h"
#include "../headers/clock_counter.h"

__BEGIN_API

Ship* Player::_player_ship;
bool Player::running = false;

Player::Player(){
    Player::_player_ship = new Ship(0.5, GameObject::Direction::UP, 400, 400, "sprites/space_ships/space_ship1.png", 10.f, 20.f);
    Player::running = true;
    std::cout << "Debug" << std::endl;
    Player::_lives = 3;
    Player::_score = 0;
}
bool Player::is_running(){
    return running;
}
sf::Sprite* Player::return_sprite(){
    
    return Player::_player_ship->get_sprite();
}

std::vector<Bullet *> * Player::getBullets(){
    return Player::_player_ship->get_bullet_list();
}

std::tuple<int,int> Player::get_player_position(){
    return Player::_player_ship->get_position();
}


void Player::run(){

    while(Player::running & Keyboard::_is_running()){
        ClockCounter::start();
        if (!Keyboard::_is_empty()){
            int action = Keyboard::pop_event();
            float delta = ClockCounter::get_time();
            switch (action){
                case 1:
                    Player::_player_ship->move(delta, GameObject::Direction::LEFT, "sprites/space_ships/space_ship2.png");
                    std::cout << "sim1" << std::endl;
                    break;
                case 2:
                    Player::_player_ship->move(delta, GameObject::Direction::RIGHT, "sprites/space_ships/space_ship4.png");
                    std::cout << "sim1" << std::endl;
                    break;
                case 3:
                    Player::_player_ship->move(delta, GameObject::Direction::DOWN, "sprites/space_ships/space_ship3.png");
                    std::cout << "sim1" << std::endl;
                    break;
                case 4:
                    Player::_player_ship->move(delta, GameObject::Direction::UP, "sprites/space_ships/space_ship1.png");
                    std::cout << "sim1" << std::endl;
                    break;
                case 5:
                    _player_ship->shoot();
                    break;
                default:
                    break;
            }
        std::cout << "Vish" << std::endl;

        }
    std::vector<Bullet *> * bullet_list = _player_ship->get_bullet_list();
    for (int i = 0; i < bullet_list->size(); i++) {
			Bullet* bullet = bullet_list->at(i);
            bullet->move(ClockCounter::get_time(), bullet->get_direction(), "sprites/space_ships/shot.png");
		}
    Thread::yield();
    }
}


__END_API
