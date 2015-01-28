#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Game
{
private:
    sf::RenderWindow _mainWindow;               //This is the window in which we will draw
    sf::Sprite _puck;                           //This is the sprite which we will display which will be the hockey puck
    sf::Sprite _paddles[2];                     //These are the two different pucks
    sf::Music _backgroundMusic;                 //Background music
    sf::Sound _hit;                             //Sound to be played when the puck is hit
    sf::Sound _goal;                            //Sound to be played when the puck lands in a goal
    sf::Sound _wall;                            //Sound to be played when the puck hits a wall
public:
    Game();
};
#endif // GAME_HPP
