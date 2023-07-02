#ifndef window_h
#define window_h

#include <iostream>
#include "main_screen.h"
#include "ship.h"
#include "enemy_controller.h"
#include <png.h>
#include <SFML/Graphics.hpp>

__BEGIN_API
class Window
{
public:
    Window();
    //~Window();
    ;

    void run();
    void draw_texture(unsigned int texture, int length, int height, float angle);
    void set_player_ship(Ship *_player_ship);
    void set_enemy_controller(EnemyController *_enemy_controller);
    void set_main_screen(mainScreen *_main_screen);
    void set_thread(Thread *_window);
    static sf::RenderWindow *get_SFML_Window();

private:
    sf::RenderWindow renderWindow;
    void load_and_bind_textures();
    Thread *_window;
    Ship *_player_ship;
    EnemyController *_enemy_controller;
    mainScreen *_main_screen;
    static sf::RenderWindow *main_window;
    sf::Texture *maze_tex;
    sf::Sprite maze_sprite;
    sf::Texture *shot_tex;
    sf::Sprite shot_sprite;
    sf::Texture *space_ship_tex;
    sf::Sprite space_ship_sprite;
    sf::Texture *enemy_ship_tex;
    sf::Sprite enemy_ship_sprite;
};

__END_API
#endif