///
///  \file StringReferenced.h
///	 \brief add a reference to a std::string
///  \date Mar 5, 2012
///  \author romain
///

#ifndef STRINGREFERENCED_H_
#define STRINGREFERENCED_H_

#include <iostream>
#include "Referenced.h"

///
/// \class StringReferenced
/// \brief add a reference to a std::string
///
class StringReferenced: public Referenced, public std::string
{
public:
    ///
    /// \brief constructor
    ///
    StringReferenced();
    ///
    /// \brief destructor
    ///
    virtual ~StringReferenced();
};

#endif /* STRINGREFERENCED_H_ */
