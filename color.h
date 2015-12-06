#ifndef COLOR_H
#define COLOR_H

#include <SFML/Graphics/Color.hpp>

#define COLOR_MAX 255

class Color
{
public:
    Color();
    Color(const Color &color);
    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha=COLOR_MAX);
    sf::Color toSFMLColor() const;
    unsigned char red() const;
    void setRed(unsigned char red);

    unsigned char green() const;
    void setGreen(unsigned char green);

    unsigned char blue() const;
    void setBlue(unsigned char blue);

    unsigned char alpha() const;
    void setAlpha(unsigned char alpha);

    static const Color BrightRed;
    static const Color Red;
    static const Color DarkRed;
    static const Color BrightGreen;
    static const Color Green;
    static const Color DarkGreen;
    static const Color BrightBlue;
    static const Color Blue;
    static const Color DarkBlue;
    static const Color BrightYellow;
    static const Color Yellow;
    static const Color DarkYellow;
    static const Color BrightCyan;
    static const Color Cyan;
    static const Color DarkCyan;
    static const Color BrightViolet;
    static const Color Violet;
    static const Color DarkViolet;
    static const Color BrightBrown;
    static const Color Brown;
    static const Color DarkBrown;
    static const Color BrightGrey;
    static const Color Grey;
    static const Color DarkGrey;
    static const Color White;
    static const Color Black;

private:
    unsigned char mRed;
    unsigned char mGreen;
    unsigned char mBlue;
    unsigned char mAlpha;
};

#endif // COLOR_H
