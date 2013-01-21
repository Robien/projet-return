///
///  \file ReferencedProtected.h
///  \brief keep the nombre of reference to a object to known when a ptr have to be destroy with SmartPtr
///  to put a class in a SmartPtr, it's nessesary to inherits from ReferencedProtected
///  \date Feb 16, 2012
///  \author romain
///

#ifndef ReferencedProtected_H_
#define ReferencedProtected_H_

#include "SmartPtr.h" // if you use a ReferencedProtected object, you are now able to use a SmartPtr
#include <boost/thread/thread.hpp>
#include "Referenced.h"

///
/// \class ReferencedProtected
/// \brief keep the nombre of reference to a object
///
class ReferencedProtected: public Referenced
{
public:
    ReferencedProtected();
    virtual ~ReferencedProtected();

public:
    friend void intrusive_ptr_add_ref(ReferencedProtected* p)
    {
        p->_m_ref.lock();
        p->ReferencedProtected::setRefUnprotected(p->ReferencedProtected::getReferenceNumberUnprotected() + 1);
        p->_m_ref.unlock();
    }
    friend void intrusive_ptr_release(ReferencedProtected* p)
    {

        p->_m_ref.lock();
        p->ReferencedProtected::setRefUnprotected(p->ReferencedProtected::getReferenceNumberUnprotected() - 1);

        if (p->ReferencedProtected::getReferenceNumberUnprotected() == 0)
        {

            p->_m_ref.unlock();
            delete p;
        }
        else
        {
            p->_m_ref.unlock();
        }
    }
    inline unsigned int getReferenceNumberUnprotected()
    {
        return Referenced::_references;
    }
    inline unsigned int getReferenceNumber()
    {
        _m_ref.lock();
        unsigned int ref = Referenced::_references;
        _m_ref.unlock();
        return ref;
    }
    ///
    /// \brief test existance of the ptr
    /// \return true if exist
    ///
    inline bool exist()
    {
        _m_ref.lock();
        bool exist = Referenced::_references > 0;
        _m_ref.unlock();
        return exist;
    }
    ///
    /// \brief test the non-existance of the ptr
    /// \return true if not exist
    ///
    inline bool isUndefined()
    {
        _m_ref.lock();
        bool def = Referenced::_references == 0;
        _m_ref.unlock();
        return def;
    }

    inline void setRef(unsigned int ref) // !!!!
    {
        _m_ref.lock();
        Referenced::_references = ref;
        _m_ref.unlock();
    }
    inline void setRefUnprotected(unsigned int ref) // !!!!
    {
        Referenced::_references = ref;
    }
protected:
    ///
    /// \brief overload of operator= to use a SmartPtr like a normal ptr
    /// \return *this
    ///
    ReferencedProtected& operator=(const ReferencedProtected&)
    {
        return *this;
    }
private:
    ReferencedProtected(const ReferencedProtected& other); //copy constructor is disable

public:
    boost::mutex _m_ref;
};

#endif /* ReferencedProtected_H_ */
