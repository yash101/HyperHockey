#ifndef FONTD_HPP
#define FONTD_HPP
#include <SFML/Graphics.hpp>
#include <map>
class fontd
{
private:
    std::map<std::string, sf::Font> _fonts;
public:
    fontd();
    sf::Font& getFont(std::string name);
    sf::Font& operator[](std::string name);
};

fontd& getFontd();
#endif // FONTD_HPP
