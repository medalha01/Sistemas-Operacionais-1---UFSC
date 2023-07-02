// Created by: Isac Martins, june 2023;

#include "lib/system.h"
#include "lib/thread.h"
#include "headers/game.h"

__USING_API

int main(void)
{
    db<Keyboard>(INF) << "Odeio Pobre";
    System::init(&Game::run);

    return 0;
}