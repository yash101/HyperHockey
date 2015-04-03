#include "textbox.hpp"
#include <iostream>



//When a key is pressed
void Textbox::textEntered(sf::Event evt)
{
    if(isActive())
    {
        if(evt.text.unicode < 128) _text += static_cast<char>(evt.text.unicode);
        if(evt.key.code == sf::Keyboard::BackSpace) _text.pop_back();
    }
}

void Textbox::keyPressed(sf::Event::KeyEvent key)
{
    if(key.code == sf::Keyboard::BackSpace) _text.pop_back();
}

void Textbox::mouseDown(float x, float y)
{
    //If the user clicked in the textbox
    if(x > _position.getX() && x < _position.getX() + _size.getX() && y > _position.getY() && y < _position.getY() + _size.getY())
    {
        //Request that we should be active
        requestActive();
    }
    else
    {
        //Make ourselves inactive
        setActive(false);
    }
}

void Textbox::mouseMove(float x, float y)
{
    if(x > _position.getX() && x < _position.getX() + _size.getX() && y > _position.getY() && y < _position.getY() + _size.getY())
    {
        _hover = true;
    }
    else
    {
        _hover = false;
    }
}

void Textbox::draw(sf::RenderWindow& window)
{
    sf::RectangleShape box;
    sf::Text text(_text, _font, _font_size);

    box.setPosition(_position.getX(), _position.getY());
    text.setPosition(_position.getX(), _position.getY());
    box.setSize(sf::Vector2f(_size.getX(), _size.getY()));

    if(!_hover && !isActive())
    {
        box.setFillColor(_backgroundColor);
        box.setOutlineColor(_borderColor);
        text.setColor(_textColor);
    }
    else if(isActive())
    {
        box.setFillColor(_backgroundColorActive);
        box.setOutlineColor(_borderColorActive);
        text.setColor(_textColorActive);
    }
    else if(_hover)
    {
        box.setFillColor(_backgroundColorHover);
        box.setOutlineColor(_borderColorHover);
        text.setColor(_textColorActive);
    }
    window.draw(box);
    window.draw(text);
}

//Not needed yet
void Textbox::mouseUp(float x, float y)
{
}



////Event handlers. Makes this class work
//void Textbox::keyPressed(sf::Event::KeyEvent key)
//{
//    if(isActive())
//    {
//        if(KeyEventToString(key) != -2) _text += KeyEventToString(key);
//        std::cout << KeyEventToString(key);
//    }
//    else if(key.code == sf::Keyboard::Key::BackSpace)
//    {
//        _text.pop_back();
//    }
//}

//void Textbox::keyReleased(sf::Event::KeyEvent key)
//{
//}

//void Textbox::mouseDown(float x, float y)
//{
//    if(x >= _position.getX() && x <= _position.getX())
//    {
//        if(y >= _position.getY() && y <= _position.getY())
//        {
//            requestActive();
//        }
//    }
//    else
//    {
//        setActive(false);
//    }
//}

//void Textbox::mouseMove(float x, float y)
//{
//    if(x >= _position.getX() && x <= _position.getX())
//    {
//        if(y >= _position.getY() && y <= _position.getY())
//        {
//            _state = HOVER;
//        }
//    }
//}

//void Textbox::mouseUp(float x, float y)
//{

//}

////Draws the textbox on the screen
//void Textbox::draw(sf::RenderWindow& window)
//{
//    sf::RectangleShape BoundingRectangle(sf::Vector2f(_size.getX(), _size.getY()));
//    BoundingRectangle.setPosition(_position.getX(), _position.getY());
//    sf::Text Text(_text, _font, _font_size);
//    if(isActive())
//    {
//        BoundingRectangle.setFillColor(_backgroundColorActive);
//    }
//    window.draw(BoundingRectangle);
//    window.draw(Text);
//}
