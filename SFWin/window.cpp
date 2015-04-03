#include "window.hpp"

Window::Window() :
    _window_name("Untitled Window"),
    _window_size(0, 0),
    _window(sf::VideoMode(_window_size.getWidth(), _window_size.getHeight()), _window_name),
    _background_color(sf::Color::White)
{}

Window::Window(int width, int height) :
    _window_name("Untitled Window"),
    _window_size(width, height),
    _window(sf::VideoMode(_window_size.getWidth(), _window_size.getHeight()), _window_name),
    _background_color(sf::Color::White)
{}

Window::Window(Vector<int> size) :
    _window_name("Untitled Window"),
    _window_size(size.getWidth(), size.getHeight()),
    _window(sf::VideoMode(_window_size.getWidth(), _window_size.getHeight()), _window_name),
    _background_color(sf::Color::White)
{}

Widget* Window::add(std::string key, Widget* type)
{
    _widgets[key] = type;
    return type;
}

void Window::remove(std::string key)
{
    _widgets.erase(key);
}

void Window::clear()
{
    _widgets.clear();
}

bool Window::update()
{
    if(!_window.isOpen()) return false;
    _window.clear(_background_color);

    for(std::map<std::string, Widget*>::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        it->second->prepare();
    }

    sf::Event evt;
    while(_window.pollEvent(evt))
    {
        if(evt.type == sf::Event::Closed)
        {
            _window.close();
            return false;
        }

        for(std::map<std::string, Widget*>::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
        {
            if(evt.type == sf::Event::MouseButtonPressed)
                it->second->mouseDown(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::MouseButtonReleased)
                it->second->mouseUp(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::MouseMoved)
                it->second->mouseMove(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y);
            else if(evt.type == sf::Event::KeyPressed)
                it->second->keyPressed(evt.key);
            else if(evt.type == sf::Event::KeyReleased)
                it->second->textEntered(evt);
            else
                it->second->eventHandler(evt);
        }
    }

    std::string whoWantsActive;
    bool anyoneWantsActive = false;

    for(std::map<std::string, Widget*>::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        if(it->second->requestingActive())
        {
            it->second->setWantingActive(false);
            anyoneWantsActive = true;
            whoWantsActive = it->first;
        }
    }

    if(anyoneWantsActive)
    {
        for(std::map<std::string, Widget*>::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
        {
            it->second->setActive(false);
        }
        _widgets[whoWantsActive]->setActive(true);
    }

    for(std::map<std::string, Widget*>::const_iterator it = _widgets.begin(); it != _widgets.end(); ++it)
    {
        it->second->draw(_window);
    }
}
