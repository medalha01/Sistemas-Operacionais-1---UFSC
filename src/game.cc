#include "../headers/game.h"

__BEGIN_API

Thread *Game::_windowThread;
Thread *Game::_keyboardThread;
Thread *Game::_playerThread;

std::unique_ptr<Window> Game::_windowObject;
std::unique_ptr<Keyboard> Game::_keyboardObject;
std::unique_ptr<Player> Game::_playerObject;
std::unique_ptr<ClockCounter> Game::_clockCounterObject;

Game::Game()
{
}

void Game::_window_run()
{
    db<Game>(INF) << "Game is starting\n";
    _windowObject = std::make_unique<Window>();
    _windowObject->run();
    _windowThread->thread_exit(3);
}
void Game::_keyboard_run()
{
    db<Game>(INF) << "Starting Keyboard \n";
    _keyboardObject = std::make_unique<Keyboard>();
    _keyboardObject->listen();
    _keyboardThread->thread_exit(3);
}

void Game::_player_run()
{
    db<Game>(INF) << "Starting Player \n";
    _playerObject = std::make_unique<Player>();
    _playerObject->run();
    _playerThread->thread_exit(3);
}

void Game::run(void *name)
{

    _clockCounterObject = std::make_unique<ClockCounter>();
    _windowThread = new Thread(_window_run);
    _keyboardThread = new Thread(_keyboard_run);
    _playerThread = new Thread(_player_run);

    
    
    
    //_windowObject->set_thread(_windowThread);
    _windowThread->join();
    _keyboardThread->join();
    _playerThread->join();
    delete _windowThread;
    delete _keyboardThread;
    delete _playerThread;
}

Game::~Game()
{
}

__END_API