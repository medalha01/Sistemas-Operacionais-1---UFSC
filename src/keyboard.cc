#include <iostream>
#include "../headers/keyboard.h"
#include "../headers/player.h"
#include "../headers/window.h"
#include <queue>

__BEGIN_API

sf::Event event;
std::queue<int> Keyboard::_event_queue;
Player *_playerController;
Window *_windowObject;
bool Keyboard::running;

Keyboard::Keyboard()
{
    /*Player* _playerController
    if (_playerController != nullptr){
        this->_playerController = _playerController;
    }
    else {
         db<Keyboard>(INF) << "Erro na construção do teclado";
    }*/

    // TODO passar o game controller
    // Era melhor passar o game ou algum controlador quem sabe
    // a propria window Window* window, Controller* controller Game* gameController
    db<Keyboard>(INF) << "Teclado Construido!\n";
}

void Keyboard::push_event(int event)
{
    _event_queue.push(event);
}

bool Keyboard::_is_empty()
{
    return _event_queue.empty();}

int Keyboard::pop_event()
{
    if (!_event_queue.empty())
    {
        int event = _event_queue.front();
        _event_queue.pop();
        return event;
    }
}

bool Keyboard::_is_running()
{
    return running;
}

Keyboard::~Keyboard()
{
}
// Player* _playerController
void Keyboard::listen()
{   
    running = true;
    sf::Window *_window_thread = Window::get_SFML_Window();
    while (_window_thread->isOpen())
    {   
        sf::Event event;
        while (_window_thread->pollEvent(event))
        {   


            switch (event.type)
            {
            case sf::Event::Closed:
                _window_thread->close();
                break;

            case sf::Event::KeyPressed:

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    _event_queue.push(1);
                    std::cout << "Left Move" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    _event_queue.push(2);
                    std::cout << "Right Move" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    _event_queue.push(3);
                    std::cout << "Down Move" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    _event_queue.push(4);
                    std::cout << "Down Up" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    _event_queue.push(5);
                    std::cout << "shoot" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    _window_thread->close();
                    break;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    _event_queue.push(9);
                    std::cout << "pause" << std::endl;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    _event_queue.push(10);
                    std::cout << "restart" << std::endl;
                }

                break;

            default:
                break;
            }Thread::yield();
        }Thread::yield();

    }

    /*

    TODO: loop para receber as inputs
    */
}

__END_API