#ifndef LABEL_HPP
#define LABEL_HPP
#include "widget.hpp"
#include <string>
class Label : public Widget
{
private:
    std::string _value;
    sf::Color _text_color;
    sf::Font _font;
    unsigned int _font_size;
    dev::Vector<float> _position;
    void configure()
    {
#ifndef DISABLE_DEFAULT_FONT
        _font.loadFromFile("resources/FontUbuntu.ttf");
#endif
        _text_color = sf::Color::Black;
        _font_size = 16;
    }
public:
    Label(std::string value) : _value(value) { configure(); }

    void setText(std::string value) { _value = value; }
    void setSize(unsigned int size) { _font_size = size; }
    void setPosition(dev::Vector<float> position) { _position = position; }
    void setColor(sf::Color color) { _text_color = color; }

    std::string getText() { return _value; }
    unsigned int getSize() { return _font_size; }
    dev::Vector<float> getPosition() { return _position; }
    sf::Color getColor() { return _text_color; }

    void draw(sf::RenderWindow& window);
};

#endif // LABEL_HPP
