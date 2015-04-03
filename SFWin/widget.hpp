#ifndef WIDGET_HPP
#define WIDGET_HPP
#include <SFML/Graphics.hpp>
class Widget
{
private:
    bool _active;
    bool _wantsActive;
public:
    Widget();
    void setActive(bool yn);
    void requestActive();
    bool requestingActive();
    bool isActive();
    void setWantingActive(bool yn);

    virtual void mouseMove(float x, float y);
    virtual void mouseDown(float x, float y);
    virtual void mouseUp(float x, float y);
    virtual void keyPressed(sf::Event::KeyEvent key);
    virtual void keyReleased(sf::Event::KeyEvent  key);
    virtual void textEntered(sf::Event event);
    virtual void eventHandler(sf::Event event);
    virtual void draw(sf::RenderWindow& window);
    virtual void prepare();
};
#endif // WIDGET_HPP
