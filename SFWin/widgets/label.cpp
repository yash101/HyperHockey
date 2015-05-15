#include "label.hpp"
#include "../fontd.hpp"
std::string& Label::text()
{
    return _text;
}

std::string Label::getText() const
{
    return _text;
}

void Label::setText(std::string text)
{
    _text = text;
    return;
}

sf::Color& Label::color()
{
    return _color;
}

sf::Color Label::getColor() const
{
    return _color;
}

void Label::setColor(sf::Color color)
{
    _color = color;
    return;
}

bool& Label::visible()
{
    return _visible;
}

void Label::makeVisible()
{
    _visible = true;
    return;
}

void Label::makeInvisible()
{
    _visible = false;
    return;
}

bool Label::isVisible() const
{
    return _visible;
}

bool Label::isInvisible() const
{
    return !_visible;
}

void Label::draw(sf::RenderWindow& window)
{
    sf::Text text;
    getFontd()["Ubuntu"];
}
