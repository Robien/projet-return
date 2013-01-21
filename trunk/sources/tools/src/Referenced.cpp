///
///  \file Referenced.cpp
///  \brief keep the nombre of reference to a object to known when a ptr have to be destroy with SmartPtr
///  to put a class in a SmartPtr, it's nessesary to inherits from referenced
///  \date Feb 16, 2012
///  \author romain
///

#include "../include/Referenced.h"

Referenced::Referenced() :
        _references(0)
{

}

Referenced::~Referenced()
{
}

