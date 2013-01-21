///
///  \file Math.h
///  \brief some math fonctions
///  \date Feb 20, 2012
///  \author romain
///

#ifndef _Math_
#define _Math_

#include <iostream>
#include <sys/types.h>
///
/// \class Math
/// \brief some math fonctions
///
class Math
{

public:
    Math();
    ~Math();

public:
    ///
    /// \brief calculate x^y
    /// \param x : x of type template
    /// \param y : y
    /// \return x^y
    ///
    template<typename T> T pow(T x, unsigned int y);
    ///
    /// \brief calculate |x|
    /// \param x : x of type template
    /// \return |x|
    ///
    template<typename T> T abs(T x);
    ///
    /// \brief calculate HW(x)
    /// \param x : x 32 bits
    /// \return hw(x)
    ///
    int hw(unsigned int x);
    ///
    /// \brief calculate HD(x, y)
    /// \param x : x 32 bits
    /// \param y : x 32 bits
    /// \return hd(x)
    ///
    int hd(unsigned int x, unsigned int y);
    ///
    /// \brief calculate HW(x)
    /// \param x : x 32 bits
    /// \return hw(x)
    ///
    int hw2(unsigned int x);
    ///
    /// \brief calculate HD(x, y)
    /// \param x : x 32 bits
    /// \param y : x 32 bits
    /// \return hd(x)
    ///
    int hd2(unsigned int x, unsigned int y);

    ///
    /// \brief return integer sup of a float
    /// \param val value
    /// \return roundsup(T val)
    ///
    template<typename T>
    int roundsup(T val);

private:

};

#include "Math.tpp" //template file
#endif
