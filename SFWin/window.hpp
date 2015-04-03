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
    template<typename T> Widget* operator[](std::string key);

    bool update();
};

#endif // WINDOW_HPP
