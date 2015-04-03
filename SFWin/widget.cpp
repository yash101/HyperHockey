#include "widget.hpp"

Widget::Widget() :
    _active(false),
    _wantsActive(false)
{}

void Widget::setActive(bool yn)
{
    _active = yn;
}

void Widget::requestActive()
{
    _wantsActive = true;
}

bool Widget::requestingActive()
{
    return _wantsActive;
}

bool Widget::isActive()
{
    return _active;
}

void Widget::setWantingActive(bool yn)
{
    _wantsActive = yn;
}

void Widget::mouseMove(float x, float y)
{
    return;
}

void Widget::mouseDown(float x, float y)
{
    return;
}

void Widget::mouseUp(float x, float y)
{
    return;
}

void Widget::keyPressed(sf::Event::KeyEvent key)
{
    return;
}

void Widget::keyReleased(sf::Event::KeyEvent key)
{
    return;
}

void Widget::textEntered(sf::Event event)
{
    return;
}

void Widget::eventHandler(sf::Event event)
{
    return;
}

void Widget::draw(sf::RenderWindow& window)
{
    return;
}

void Widget::prepare()
{
    return;
}
