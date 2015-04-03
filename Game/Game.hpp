#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "screen.hpp"
class Game
{
private:
    Screen _screen;
    sf::Sprite _puck;                           //This is the sprite which we will display which will be the hockey puck
    sf::Sprite _paddles[2];                     //These are the two different pucks
    sf::Music _backgroundMusic;                 //Background music
    sf::SoundBuffer _hit;                       //Sound to be played when the puck is hit
    sf::SoundBuffer _goal;                      //Sound to be played when the puck lands in a goal
    sf::SoundBuffer _wall;                      //Sound to be played when the puck hits a wall
    std::vector<sf::Event> _priorEvents;        //Prior Events
public:
    Game();
    void mainMenu();
    void mainMenuCallback();
};
#endif // GAME_HPP
