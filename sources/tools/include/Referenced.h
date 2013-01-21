///
///  \file Referenced.h
///  \brief keep the nombre of reference to a object to known when a ptr have to be destroy with SmartPtr
///  to put a class in a SmartPtr, it's nessesary to inherits from Referenced
///  \date Feb 16, 2012
///  \author romain
///

#ifndef REFERENCED_H_
#define REFERENCED_H_

#include "SmartPtr.h" // if you use a Referenced object, you are now able to use a SmartPtr

//#include "MemManager.h"

///
/// \class Referenced
/// \brief keep the nombre of reference to a object
///
class Referenced
{
public:
    Referenced();
    virtual ~Referenced();

public:
    friend void intrusive_ptr_add_ref(Referenced* p)
    {
        ++p->_references;
    }
    friend void intrusive_ptr_release(Referenced* p)
    {
        if (--p->_references == 0)
        {
//            MemManager::get()->ptrToDelete(p);
            delete p;
        }
    }
    virtual inline unsigned int getReferenceNumber()
    {
        return _references;
    }
    ///
    /// \brief test existance of the ptr
    /// \return true if exist
    ///
    virtual inline bool exist()
    {
        return _references > 0;
    }
    ///
    /// \brief test the non-existance of the ptr
    /// \return true if not exist
    ///
    virtual inline bool isUndefined()
    {
        return _references == 0;
    }

    virtual inline void setRef(unsigned int ref) // !!!!
    {
        _references = ref;
    }
protected:
    ///
    /// \brief overload of operator= to use a SmartPtr like a normal ptr
    /// \return *this
    ///
    Referenced& operator=(const Referenced&)
    {
        return *this;
    }
private:
    Referenced(const Referenced& other); //copy constructor is disable

protected:
    unsigned int _references;
};

#endif /* REFERENCED_H_ */
