#ifndef GAME_H
#define GAME_H

#include "../lib/traits.h"
#include "../lib/thread.h"
#include "window.h"
#include "keyboard.h"  
#include "player.h"
#include "enemy_controller.h"
#include "clock_counter.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


__BEGIN_API

class Game
{
private:
    static Thread* _windowThread;
    static Thread* _keyboardThread;
    static Thread* _enemyControllerThread;
    static Thread* _playerThread;
    static Thread* _collisionManager;   

    static std::unique_ptr<Window> _windowObject;
    static std::unique_ptr<Keyboard> _keyboardObject;
    static std::unique_ptr<Player> _playerObject;
    static std::unique_ptr<ClockCounter> _clockCounterObject;
    static EnemyController* _enemyControllerObject;


    static void _window_run();
    static void _keyboard_run();
    static void _player_run();
    static void _collisionManager_run();
    static void _enemy_controller_run();
public:
    Game();
    ~Game();
    static void run(void* name);
};

__END_API


#endif