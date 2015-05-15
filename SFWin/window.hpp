#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "../DevLib2/vector.hpp"
#include "widget.hpp"
#include <SFML/Graphics.hpp>
#include <map>
class Window
{
private:
    Vector<int> _window_size;
    sf::RenderWindow _window;
    sf::Color _background_color;
    std::string _window_name;
    std::map<std::string, Widget*> _widgets;
public:
    Window();
    Window(int width, int height);
    Window(Vector<int> size);

    Widget* add(std::string key, Widget* widget);
    void clear();
    void remove(std::string key);
    Widget* operator[](std::string key);
    Widget* get(std::string key);

    bool update();

    Vector<int>& setSize(Vector<int>& size);
    Vector<int> getSize();
    Vector<int>& size();

    Vector<int>& setPosition(Vector<int>& position);
    Vector<int> getPosition();

    sf::Color& setBackgroundColor(sf::Color& color);
    sf::Color getBackgroundColor();
    sf::Color& backgroundColor();

    std::string& setText(std::string& text);
    std::string getText();

    bool hasFocus();
    bool isActive();

    void setActive(bool yn);

    sf::RenderWindow& getRenderWindow();

    int setFramerateLimit(int limit);
    bool enableFramerateLimit(bool yn);

    void close();
};
#endif // WINDOW_HPP
