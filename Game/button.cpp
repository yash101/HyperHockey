#include "button.hpp"
#include <iostream>
void Button::mouseDown(float x, float y)
{
    if(x >= _position.getX() && x <= _position.getX() + _size.getX())
        if(y >= _position.getY() && y <= _position.getY() + _size.getY())
        {
            _callback();
            _callback_lb();
            requestActive();
        }
        else setActive(false);
    else setActive(false);
}

void Button::mouseUp(float x, float y)
{
    setActive(false);
}

void Button::mouseMove(float x, float y)
{
    if(x >= _position.getX() && x <= _position.getX() + _size.getX())
        if(y >= _position.getY() && y <= _position.getY() + _size.getY())
            if(!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
                 || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)
                 || sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)))
                _hover = true;
            else _hover = false;
        else _hover = false;
    else _hover = false;
}

void Button::draw(sf::RenderWindow& window)
{
    sf::RectangleShape rect(sf::Vector2f(_size.getX(), _size.getY()));
    rect.setPosition(sf::Vector2f(_position.getX(), _position.getY()));
    sf::Text text(_text, _font, _font_size);
    text.setPosition(rect.getPosition());
    rect.setOutlineThickness(_border_size);

    if(!_hover)
    {
        rect.setOutlineColor(_borderColor);
        rect.setFillColor(_fillColor);
        text.setColor(_textColor);
    }
    else
    {
        rect.setOutlineColor(_borderHoverColor);
        rect.setFillColor(sf::Color::Red);
        text.setColor(_textHoverColor);
    }

    if(isActive()) rect.setFillColor(sf::Color::White);

    window.draw(rect);
    window.draw(text);
}
