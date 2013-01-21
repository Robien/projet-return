///
///  \file SmartPtr.h
///  \brief used to avoid leak memory
///  \date Feb 16, 2012
///  \author romain
///

#ifndef _SmartPtr_
#define _SmartPtr_

#include <boost/intrusive_ptr.hpp>
#include <boost/thread/thread.hpp>
///
/// \class SmartPtr
/// \brief used to avoid leak memory
///
template<class T>
class SmartPtr: public boost::intrusive_ptr<T>
{

public:
    SmartPtr()
    {
    }
    SmartPtr(T* t)
    {
        reset(t);
    }
    virtual ~SmartPtr()
    {
    }

public:
    void operator=(T* p)
    {
        reset(p);
    }
    operator T*()
    {
        T* tmp = this->get();
        return tmp;
    }

};

#endif
