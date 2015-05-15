#ifndef LABEL_HPP
#define LABEL_HPP
#include "../widget.hpp"
#include "../../DevLib2/vector.hpp"
#include <string>
class Label : public Widget
{
private:
    std::string _text;
    sf::Color _color;
    Vector<size_t> _position;
    bool _visible;
public:
    std::string& text();
    std::string getText() const;
    void setText(std::string text);

    sf::Color& color();
    sf::Color getColor() const;
    void setColor(sf::Color color);

    Vector<size_t>& position();
    Vector<size_t> getPosition() const;
    void setPosition(Vector<size_t> color);

    bool& visible();
    void makeVisible();
    void makeInvisible();
    bool isVisible() const;
    bool isInvisible() const;

    void draw(sf::RenderWindow& window);
};
#endif // LABEL_HPP
