#ifndef SCREEN_HPP
#define SCREEN_HPP
#include <SFML/Graphics.hpp>
#include "widget.hpp"
#include <map>
class Screen
{
private:
//    std::vector<std::shared_ptr<Widget> > _widgets;
    std::map<std::string, std::shared_ptr<Widget> > _widgets;
    sf::RenderWindow _window;
    sf::Color _background_color;
    dev::Vector<unsigned int> _window_size;
    std::string _windowName;
public:
    Screen(dev::Vector<unsigned int> ScreenSize, std::string ScreenName);

    template<typename WidgetType> void add(std::string key, WidgetType& widget)         //Adds a widget onto the Screen.
        { _widgets[key] = std::make_shared<WidgetType>(widget); }
    void clear();                                                                       //Removes all widgets from the Screen
    void remove(std::string key) { _widgets.erase(key); }                               //Removes a single widget from the Screen
    template<typename T> std::shared_ptr<T>& operator[](std::string key) { return _widgets[key]; }  //BROKEN. Returns a shared
                                                                                                    //pointer to the selected
                                                                                                    //widget.

    //Window manupulation functions
    //---> GETTERS
    dev::Vector<float> getSize() { return dev::Vector<float>(_window.getSize().x, _window.getSize().y); }           //Returns the
                                                                                                                    //window size
    dev::Vector<int> getPosition() { return dev::Vector<int>(_window.getPosition().x, _window.getPosition().y); }   //Returns the
                                                                                                                    //window position
    bool hasFocus() { return _window.hasFocus(); }          //Is the window in focus?
    bool isOpen() { return _window.isOpen(); }              //Is the window still open?
    //---> SETTERS
    void setBackgroundColor(sf::Color color) { _background_color = color; }         //Sets the background color of the window. Must
                                                                                    //display() to update!
    void setActive(bool active) { _window.setActive(active); }      //Make the window active (or not)
    void setFramerateLimit(unsigned int fps) { _window.setFramerateLimit(fps); }        //Set a framerate limit (VSync)
    void setIcon(unsigned int width, unsigned int height, sf::Uint8* data) { _window.setIcon(width, height, data); }        //Set the window icon
    void setPosition(dev::Vector<int> position) { _window.setPosition(sf::Vector2i(position.getX(), position.getY())); }    //Set the window position
    void setSize(dev::Vector<unsigned int> size) { _window.setSize(sf::Vector2u(size.getX(), size.getY())); }               //Sets the window size
    void setTitle(std::string title) { _window.setTitle(title); }       //Set the title of the window
    void setVerticalSyncEnabled(bool yn) { _window.setVerticalSyncEnabled(yn); }        //turn on and off VSync
    void setVisible(bool yn) { _window.setVisible(yn); }        //Set the visibility of the window
    void requestFocus() { _window.requestFocus(); }     //Make the window have focus

    //Screenshots
    sf::Image capture() const { return _window.capture(); }     //Capture a screenshot

    //Updates the screen
    bool update();
    //Closes the screen
    void close() { _window.close(); }
};

#endif // SCREEN_HPP
