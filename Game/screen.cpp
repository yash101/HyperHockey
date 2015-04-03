#include "screen.hpp"

//Default construction. This takes a screen size and a handle name for the screen!
//Screen::Screen(dev::Vector<unsigned int> ScreenSize, std::string ScreenName) :
//    _window(sf::VideoMode(ScreenSize.getX(), ScreenSize.getY()), ScreenName)        //Initialize our main window
//{
//}
Screen::Screen(dev::Vector<unsigned int> ScreenSize, std::string ScreenName) :
    _window_size(ScreenSize),
    _window(sf::VideoMode(ScreenSize.getX(), ScreenSize.getY()), ScreenName),
    _windowName(ScreenName)
{
}

bool Screen::update()
{
    //==============================//
    //Prepare the window. If the window is not open, return the function and let the programmer
    //know that the window has been closed!
    if(!_window.isOpen()) return false;
    _window.clear(_background_color);

    for(std::map<std::string, std::shared_ptr<Widget> >::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        (*(*it).second).prepare();
    }

    //==============================//

    //------------------------------//

    //==============================//
    //Check for events and call the event handlers on each stached object!
    sf::Event evt;
    while(_window.pollEvent(evt))
    {
        //Check to see if the window has been closed
        if(evt.type == sf::Event::Closed) { _window.close(); return false; }

        //Handle the events, for each Widget. Iterate through each widget and call it's event handlers
        for(std::map<std::string, std::shared_ptr<Widget> >::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
        {
            if(evt.type == sf::Event::MouseButtonPressed)           //Mouse button pressed
                (*(*it).second).mouseDown(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::MouseButtonReleased)     //Mouse button released
                (*(*it).second).mouseUp(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::MouseMoved)              //Mouse is moved
                (*(*it).second).mouseMove(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::KeyPressed)              //Key is pressed
                (*(*it).second).keyPressed(evt.key);
            else if(evt.type == sf::Event::KeyReleased)             //Key is released
                (*(*it).second).keyPressed(evt.key);
            else if(evt.type == sf::Event::TextEntered)
                (*(*it).second).textEntered(evt);
            else (*(*it).second).eventHandler(evt);                 //Handle all other events
        }
    }
    //==============================//

    //------------------------------//

    //==============================//
    //Check and see if any widgets want to be flagged as "Active". This isn't going to prevent other items from
    //themselves changing the values. It, however, provides a method to request sole "permissions" that other objects
    //are told not to use!
    std::string whoWantsActive;
    bool anyoneWantsActive = false;
    for(std::map<std::string, std::shared_ptr<Widget> >::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        if((*(*it).second).requestingActive())
        {
            (*(*it).second).setWantingActive(false);
            anyoneWantsActive = true;
            whoWantsActive = (*it).first;
        }
    }
    if(anyoneWantsActive)
    {
        for(std::map<std::string, std::shared_ptr<Widget> >::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
        {
            (*(*it).second).setActive(false);
        }
        (*_widgets[whoWantsActive]).setActive(true);
    }
    //==============================//

    //------------------------------//

    //==============================//
    //Call the display functions on each piece in the window! These are the functions in which the objects draw themseles
    //on the screen
    for(std::map<std::string, std::shared_ptr<Widget> >::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        (*(*it).second).draw(_window);
    }
    _window.display();
    //==============================//

    //------------------------------//

    //==============================//
    //Return this function. We finished all the way through, so we will send a true. This function is designed to be used
    //as while(Screen.display()) doSomething();
    return true;
    //==============================//
}

void Screen::clear()
{
    _widgets.clear();
}
