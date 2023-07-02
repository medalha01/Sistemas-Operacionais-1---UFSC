#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include "../lib/thread.h"
#include "../lib/traits.h"
#include "./ship.h"
#include <queue>

__BEGIN_API

class Player
{
    private:
        Thread * _player_thread;
        static Ship* _player_ship;
        int _lives;
        int _score;
        static bool running;
        static std::queue<int> _action_queue;
        void die();
        
    
    public:
        Player();
        //~Player();
        static bool is_running();
        static std::tuple<int,int> get_player_position();
        static void increaseScore();
        static sf::Sprite* return_sprite();
        static std::vector<Bullet *> * getBullets();
        void run();


};

__END_API

#endif