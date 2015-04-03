#include "label.hpp"
#include <iostream>
void Label::draw(sf::RenderWindow& window)
{
    sf::Text lbl(_value, _font, _font_size);
    lbl.setPosition(sf::Vector2f(_position.getX(), _position.getY()));
    lbl.setColor(_text_color);
    window.draw(lbl);
}
