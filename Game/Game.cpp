#include "Game.hpp"
Game::Game() :
    _mainWindow(sf::VideoMode(240, 320), "Hyper Hockey!")
{
    _mainWindow.setActive(true);
    _mainWindow.clear();
}
