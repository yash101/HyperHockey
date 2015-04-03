#include "Game.hpp"
#include "config.hpp"
Game::Game() :
    _screen(dev::Vector<int>(WINDOW_W, WINDOW_H), "HyperHockey!")
{
    _screen.setBackgroundColor(sf::Color::Black);
    mainMenu();
}
