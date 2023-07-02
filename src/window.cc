#include "../headers/window.h"
#include "../headers/sprite_singleton.h"
#include "../lib/thread.h"
#include "../headers/clock_counter.h"
#include "../headers/player.h"

__BEGIN_API

sf::RenderWindow* Window::main_window;


Window::Window()
{   
    load_and_bind_textures();
    renderWindow.create(sf::VideoMode(815, 560), "Brick Game");
    // Ship* _player_ship;
    mainScreen* _main_screen = new mainScreen("sprites/maze/screen.png");
    // EnemyController* _enemy_controller;
}

void Window::draw_texture(unsigned int texture, int length, int height, float angle)
{
}

sf::RenderWindow * Window::get_SFML_Window(){
    return main_window;
}

void Window::set_thread(Thread *_window)
{
    this->_window = _window;
}

void Window::run()
{   
    renderWindow.setFramerateLimit(120);
    Window::main_window = &renderWindow;
    // Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    renderWindow.setKeyRepeatEnabled(true);
    while (renderWindow.isOpen())
    {   
        if (Player::is_running()){
        ClockCounter::start();
        renderWindow.clear();

        renderWindow.draw(*Player::return_sprite());
        renderWindow.draw(*mainScreen::getSprite());
        std::vector<Bullet *> * bullet_list = Player::getBullets();
        for (int i = 0; i < bullet_list->size(); i++) {
			Bullet* bullet = bullet_list->at(i);
            renderWindow.draw(*bullet->get_sprite());
		}
        /*
        std::tuple player_position = Ship::get_position(_player_ship);
        space_ship_sprite.setPosition(std::get<0>(player_position), std::get<1>(player_position));*/
        //window.draw(space_ship_sprite);

        //window.draw(enemy_ship_sprite);

        //window.draw(shot_sprite);

        renderWindow.display();

        }Thread::yield();
    }
}

void Window::load_and_bind_textures()
{   
    sf::Texture space_ship_tex;
    space_ship_tex.loadFromFile("sprites/space_ships/space_ship1.png");
    space_ship_sprite.setTexture(space_ship_tex);
    space_ship_sprite.scale(1, 1);

    
    // Bind map textures
    sf::Texture maze_tex;
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(1.5, 1.5);
    /*maze_tex = _main_screen->get_maze()->get_texture();
    maze_sprite.setTexture(*maze_tex);
    float scale = _main_screen->get_maze()->get_scale();
    maze_sprite.scale(scale, scale);*//*

    shot_tex.loadFromFile("sprites/space_ships/shot.png");
    shot_sprite.setTexture(shot_tex);
    shot_sprite.scale(-0.5, -0.5);


    enemy_ship_tex.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    enemy_ship_sprite.setTexture(enemy_ship_tex);
    enemy_ship_sprite.scale(-0.5, -0.5);*/
}

__END_API