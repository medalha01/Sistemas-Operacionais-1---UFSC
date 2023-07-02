#ifndef SPRITE_H
#define SPRITE_H

#include "../lib/thread.h"
#include "../lib/traits.h"
#include <string>

using namespace std;

class Sprites{
    private:
        string enemySpriteRight = "../sprites/enemy_space_ship_right.png";
        string enemySpriteLeft = "../sprites/enemy_space_ship_left.png";
        string enemySpriteUp = "./sprites/enemy_space_ship_up.png";
        string enemySpriteDown = "./sprites/enemy_space_ship_down.png";
        string playerDown = "./sprites/player_space_ship_down.png";
        string playerUp = "./sprites/player_space_ship_up.png";
        string playerLeft = "./sprites/player_space_ship_left.png";
        string playerRight = "./sprites/player_space_ship_right.png";
        string bullet = "./sprites/bullet.png";

        float playerSpeed = 100.f;

    public:
        static string getBullet(){};

        static string getEnemyRight();
        static string getEnemyLeft();
        static string getEnemyUp();
        static string getEnemyDown();
        static string getPlayerDown();
        static string getPlayerUp();
        static string getPlayerLeft();
        static string getPlayerRight();

};


#endif