#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/window.h"
#include "../headers/player.h"
#include "../lib/traits.h"
#include "../lib/thread.h"
#include <queue>
#include <string>
__BEGIN_API

class Player;

class Keyboard
{
public:
    // Keyboard(Player *_playerController, Thread *_player_thread, sf::RenderWindow *_window_thread);
    Keyboard();
    ~Keyboard();

    static void listen();
    static void run();
    static bool _is_empty();
    static bool _is_running();
    static int pop_event();
    

private:
    sf::Event event;
    static void push_event(int event);
    static bool running;
    static std::queue<int> _event_queue;
    Player *_playerController;
    std::unique_ptr<Window> _windowObject;
};

__END_API

#endif