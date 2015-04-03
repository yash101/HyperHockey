#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#ifdef __cpp_lambdas
#include <functional>
#endif
inline void doNothing() {}
class Button : public Widget
{
private:
    void (*_callback)();
    dev::Vector<float> _position;
    dev::Vector<float> _size;
    sf::Color _fillColor;
    sf::Color _borderColor;
    sf::Color _textColor;
    sf::Color _textHoverColor;
    sf::Color _fillHoverColor;
    sf::Color _borderHoverColor;
    std::string _text;
    sf::Font _font;
    float _font_size;
    bool _hover;
    float _border_size;
#ifdef __cpp_lambdas
    std::function<void()> _callback_lb;
#endif
public:
    Button(void (*callback)()) :
        _font_size(16),
        _fillColor(sf::Color::Green),
        _borderColor(sf::Color::Black),
        _textColor(sf::Color::Black),
        _hover(false),
        _callback(callback),
        _fillHoverColor(sf::Color::Red),
        _borderHoverColor(sf::Color::Green),
        _textHoverColor(sf::Color::Blue),
        _border_size(2)
#ifdef __cpp_lambdas
        ,_callback_lb([](){})
#endif
    {
        _font.loadFromFile("resources/FontUbuntu.ttf");
    }

#ifdef __cpp_lambdas
    Button(std::function<void()> funct) :
        _font_size(16),
        _fillColor(sf::Color::Green),
        _borderColor(sf::Color::Red),
        _textColor(sf::Color::Black),
        _hover(false),
        _callback(doNothing),
        _fillHoverColor(sf::Color::Red),
        _borderHoverColor(sf::Color::Green),
        _textHoverColor(sf::Color::Blue),
        _border_size(2)
#ifdef __cpp_lambdas
       ,_callback_lb(funct)
#endif
    {
        _font.loadFromFile("resources/FontUbuntu.ttf");
    }
#endif

    Button() :
        _font_size(16),
        _fillColor(sf::Color::Green),
        _borderColor(sf::Color::Red),
        _textColor(sf::Color::Black),
        _hover(false),
        _callback(doNothing),
        _fillHoverColor(sf::Color::Red),
        _borderHoverColor(sf::Color::Green),
        _textHoverColor(sf::Color::Blue),
        _border_size(2)
    {
        _font.loadFromFile("resources/FontUbuntu.ttf");
    }

    void setCallback(void(*callback)()) { _callback = callback; }

    void draw(sf::RenderWindow& window);

    void setSize(dev::Vector<float> Size) { _size = Size; }
    void setPosition(dev::Vector<float> Position) { _position = Position; }

    void setFillColor(sf::Color color) { _fillColor = color; }
    void setBorderColor(sf::Color color) { _borderColor = color; }
    void setTextColor(sf::Color color) { _textColor = color; }

    void setBorderSize(float size) { _border_size = size; }

    void setBorderHoverColor(sf::Color color) { _borderHoverColor = color; }
    void setFillHoverColor(sf::Color color) { _fillHoverColor = color; }
    void setTextHoverColor(sf::Color color) { _textHoverColor = color; }

    void setFont(std::string location) { _font.loadFromFile(location); }
    void setFontSize(float size) { _font_size = size; }
    void setText(std::string text) { _text = text; }

    void mouseDown(float x, float y);
    void mouseMove(float x, float y);
    void mouseUp(float x, float y);
};

#endif // BUTTON_HPP
