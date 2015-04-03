#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include "widget.hpp"
#ifdef __cpp_lambdas
#include <functional>
#endif
#include <string>
class Textbox : public Widget
{
private:
    //********** {CALLBACK FUNCTIONS}
    //Enable lambdas if they are supported
#ifdef __cpp_lambdas
    std::function<std::string()> _callback;
#endif
    //This is a regular c function pointer
    std::string (*_callback_c)();

    //Position and size
    dev::Vector<float> _size;
    dev::Vector<float> _position;

    //Colors
    sf::Color _backgroundColor;         //--->Default background
    sf::Color _backgroundColorHover;    //--->Hover background
    sf::Color _backgroundColorActive;   //--->Active background
    sf::Color _borderColor;             //--->Default border
    sf::Color _borderColorHover;        //--->Hover border
    sf::Color _borderColorActive;       //--->Active border
    sf::Color _textColor;               //--->Default text
    sf::Color _textColorHover;          //--->Hover text
    sf::Color _textColorActive;         //--->ActiveText

    //Current text to be drawn
    std::string _text;

    //Font
    sf::Font _font;
    unsigned int _font_size;
    bool _enabled;
    bool _hover;

    //Sets the default value for everything
    void construct()
    {
        _position = dev::Vector<float>(0, 0);
        _size = dev::Vector<float>(100, 20);
#ifndef DISABLE_DEFAULT_FONT
        _font.loadFromFile("resources/FontUbuntu.ttf");
#endif
        _backgroundColor = sf::Color::Green;
        _backgroundColorHover = sf::Color::White;
        _backgroundColorActive = sf::Color::Cyan;
        _borderColor = sf::Color::Red;
        _borderColorHover = sf::Color::Green;
        _borderColorActive = sf::Color::Black;
        _textColor = sf::Color::Red;
        _textColorHover = sf::Color::Green;
        _textColorActive = sf::Color::Black;
        _enabled = true;
        _hover = false;
        _font_size = 12;
    }
public:
    //Default constructor (Do nothing!)
    Textbox() {construct();}

    //Set the callback functions
    void setCallback(std::function<std::string()> callback)
        { _callback = callback; _callback_c = NULL; }
    void setCallback(std::string (*callback)())
        { _callback_c = callback; _callback = NULL; }

    //Event handlers
    void mouseMove(float x, float y);
    void mouseDown(float x, float y);
    void mouseUp(float x, float y);
    void keyPressed(sf::Event::KeyEvent evt);
    void textEntered(sf::Event evt);

    //Draws the textbox on the screen
    void draw(sf::RenderWindow& window);

    //Getters
    sf::Color getBackgroundColor() { return _backgroundColor; }
    sf::Color getBackgroundColorHover() { return _backgroundColorHover; }
    sf::Color getBackgroundColorActive() { return _backgroundColorActive; }
    sf::Color getBorderColor() { return _borderColor; }
    sf::Color getBorderColorHover() { return _borderColorHover; }
    sf::Color getBorderColorActive() { return _borderColorActive; }
    sf::Color getTextColor() { return _textColor; }
    sf::Color getTextColorHover() { return _textColorHover; }
    sf::Color getTextColorActive() { return _textColorActive; }
    std::string getText() { return _text; }
    unsigned int getFontSize() { return _font_size; }
    dev::Vector<float> getPosition() { return _position; }
    dev::Vector<float> getSize() { return _size; }

    //Setters
    void setBackgroundColor(sf::Color color) { _backgroundColor = color; }
    void setBackgroundColorHover(sf::Color color) { _backgroundColorHover = color; }
    void setBackgroundColorActive(sf::Color color) { _backgroundColorActive = color; }
    void setBorderColor(sf::Color color) { _borderColor = color; }
    void setBorderColorHover(sf::Color color) { _borderColorHover = color; }
    void setBorderColorActive(sf::Color color) { _borderColorActive = color; }
    void setTextColor(sf::Color color) { _textColor = color; }
    void setTextColorHover(sf::Color color) { _textColorHover = color; }
    void setTextColorActive(sf::Color color) { _textColorActive = color; }
    void setText(std::string text) { _text = text; }
    void setFontSize(unsigned int value) { _font_size = value; }
    void setPosition(dev::Vector<float> position) { _position = position; }
    void setSize(dev::Vector<float> size) { _size = size; }

    //Gives a reference to the font
    sf::Font& font() { return _font; }

    //Clear the textbox
    void clear() { _text.clear(); }

    //Controlling the input and output of the text box
    void disable() { _enabled = false; }
    void enable() { _enabled = true; }
};

#endif // TEXTBOX_HPP
