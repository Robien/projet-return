///
///  \file Math.cpp
///  \brief some math fonctions
///  \date Feb 20, 2012
///  \author romain
///

#include "Math.h"

Math::Math()
{
}

Math::~Math()
{
}

int Math::hw(unsigned int x) // WTF ???
{
    x -= ((x >> 1) & 0x55555555);
    x = ((x >> 2) & 0x33333333) + (x & 0x33333333); //l'hexa c'est extra
    x = (((x >> 4) + x) & 0x0f0f0f0f);
    x += (x >> 8);
    x += (x >> 16);
    return (x & 0x0000003f);
}

int Math::hd(unsigned int x, unsigned int y)
{
    return (hw(x ^ y));
}

int Math::hw2(unsigned int  x)
{
    x = x - ((x >> 1) & 033333333333) - ((x >> 2) & 011111111111); //l'octal c'est pas banal
    x = (x + (x >> 3)) & 030707070707;
    return x % 63; // <3 love
}

int Math::hd2(unsigned int  x, unsigned int  y)
{
    return (hw(x ^ y));
}
