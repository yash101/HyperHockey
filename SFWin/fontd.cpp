#include "fontd.hpp"
sf::Font& fontd::getFont(std::string name)
{
    return _fonts[name];
}

sf::Font& fontd::operator[](std::string name)
{
    return _fonts[name];
}

fontd::fontd()
{}

fontd _fontd;

class st_t
{
public:
    st_t()
    {}
} _starter;

#ifndef defaultFont
#if defined(__MACH__)
#define defaultFont "/Library/Fonts/Microsoft/Arial.ttf"
#elif defined(__linux__) || defined(__linux) || defined(_linux)
#elif defined(__WIN32) || defined(__WIN32__)
#endif
#endif

fontd& getFontd()
{
    return _fontd;
}
