#include "color.h"

Color::Color() : mRed(0), mGreen(0), mBlue(0), mAlpha(255)
{
}

Color::Color(const Color &color) : Color(color.red(),color.green(),color.blue(),color.alpha())
{

}

Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : mRed(red), mGreen(green), mBlue(blue), mAlpha(alpha)
{

}

sf::Color Color::toSFMLColor() const
{
    return sf::Color(mRed,mGreen,mBlue,mAlpha);
}
unsigned char Color::red() const
{
    return mRed;
}

void Color::setRed(unsigned char red)
{
    mRed = red;
}
unsigned char Color::green() const
{
    return mGreen;
}

void Color::setGreen(unsigned char green)
{
    mGreen = green;
}
unsigned char Color::blue() const
{
    return mBlue;
}
void Color::setBlue(unsigned char blue)
{
    mBlue = blue;
}
unsigned char Color::alpha() const
{
    return mAlpha;
}

void Color::setAlpha(unsigned char alpha)
{
    mAlpha = alpha;
}

const Color Color::BrightRed = Color(COLOR_MAX,0,0);
const Color Color::Red = Color(2*COLOR_MAX/3,0,0);
const Color Color::DarkRed = Color(COLOR_MAX/3,0,0);
const Color Color::BrightGreen = Color(0,COLOR_MAX,0);
const Color Color::Green = Color(0,2*COLOR_MAX/3,0);
const Color Color::DarkGreen = Color(0,COLOR_MAX/3,0);
const Color Color::BrightBlue = Color(0,0,COLOR_MAX);
const Color Color::Blue = Color(0,0,2*COLOR_MAX/3);
const Color Color::DarkBlue = Color(0,0,COLOR_MAX/3);
const Color Color::BrightYellow = Color(COLOR_MAX,COLOR_MAX,0);
const Color Color::Yellow = Color(2*COLOR_MAX/3,2*COLOR_MAX/3,0);
const Color Color::DarkYellow = Color(COLOR_MAX/3,COLOR_MAX/3,0);
const Color Color::BrightCyan = Color(0,COLOR_MAX,COLOR_MAX);
const Color Color::Cyan = Color(0,2*COLOR_MAX/3,2*COLOR_MAX/3);
const Color Color::DarkCyan = Color(0,COLOR_MAX/3,COLOR_MAX/3);
const Color Color::BrightViolet = Color(COLOR_MAX,0,COLOR_MAX);
const Color Color::Violet = Color(2*COLOR_MAX/3,0,2*COLOR_MAX/3);
const Color Color::DarkViolet = Color(COLOR_MAX/3,0,COLOR_MAX/3);
const Color Color::BrightBrown = Color();
const Color Color::Brown = Color();
const Color Color::DarkBrown = Color();
const Color Color::BrightGrey = Color(3*COLOR_MAX/4,3*COLOR_MAX/4,3*COLOR_MAX/4);
const Color Color::Grey = Color(COLOR_MAX/2,COLOR_MAX/2,COLOR_MAX/2);
const Color Color::DarkGrey = Color(COLOR_MAX/4,COLOR_MAX/4,COLOR_MAX/4);
const Color Color::White = Color(COLOR_MAX,COLOR_MAX,COLOR_MAX);
const Color Color::Black = Color(0,0,0);
