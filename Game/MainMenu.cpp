#include "Game.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include "config.hpp"
#include <iostream>
#include "button.hpp"
#include "textbox.hpp"
#include "label.hpp"
void Game::mainMenu()
{
    _screen.clear();
    bool selected = false;
    bool con = false;

    Button connect([&](){ selected = true; con = true; });
    connect.setPosition(dev::Vector<float>(16, 16));
    connect.setSize(dev::Vector<float>(_screen.getSize().getX() - 32, 20));
    connect.setText("Connect to Game!");

    Button host([&](){ selected = true; con = false; });
    host.setPosition(dev::Vector<float>(16, 16 + 16 + 20));
    host.setSize(dev::Vector<float>(_screen.getSize().getX() - 32, 20));
    host.setText("Host Game!");

    _screen.add("ConnectButton", connect);
    _screen.add("HostButton", host);

    //Update and keep the screen fresh until we have recieved the input!
    while(_screen.update() && !selected) {}

    _screen.clear();    //Clear the screen. We don't have anything left to display!

    if(con)
    {
        selected = false;
        Label uriLabel("Server Address:");
        uriLabel.setPosition(dev::Vector<float>(16, 16));
        uriLabel.setSize(16);
        uriLabel.setColor(sf::Color::White);
        Textbox uri;
        uri.setPosition(dev::Vector<float>(16, 36));
        uri.setSize(dev::Vector<float>(_screen.getSize().getX() - 32, 20));
        _screen.add("Label", uriLabel);
        _screen.add("URI", uri);
    }

    while(_screen.update()) {}   //Push changes to the screen. This will remove all elements from the screen!
}
