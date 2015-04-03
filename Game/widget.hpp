#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "../DevLib/vector.hpp"
#include <SFML/Graphics.hpp>
class Widget
{
protected:
    bool _active, _wantsActive;
public:
    Widget() : _active(false), _wantsActive(false) {}
    void setActive(bool val) { _active = val; }             //NEVER USE THIS FUNCTION. SOLELY FOR SCREEN CLASS TO USE
    void requestActive() { _wantsActive = true; }           //USE THIS INSTEAD OF setActive();
    bool requestingActive() { return _wantsActive; }
    bool isActive() { return _active; }
    void setWantingActive(bool val) { _wantsActive = val; } //AGAIN, NEVER USE!!!
    virtual void mouseMove(float x, float y);
    virtual void mouseDown(float x, float y);
    virtual void mouseUp(float x, float y);
    virtual void keyPressed(sf::Event::KeyEvent key);
    virtual void keyReleased(sf::Event::KeyEvent key);
    virtual void textEntered(sf::Event evt);
    virtual void eventHandler(sf::Event event);
    virtual void draw(sf::RenderWindow& window);
    virtual void prepare() {}
};
#endif // WIDGET_HPP
