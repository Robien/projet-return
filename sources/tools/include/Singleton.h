///
///  \file Singleton.h
///  \brief a Singleton is a class instancied only once.
///  \date Feb 16, 2012
///  \author romain
///

#ifndef SINGLETON_H_
#define SINGLETON_H_

///
/// \class Singleton
/// \brief a Singleton is a class instancied only once.
///
template<typename T>
class Singleton
{

public:
    ///
    /// \brief test if the singleton is alredy instancied
    /// \return true if instancied
    ///
    static inline bool isDefine()
    {
        return (s == 0);
    }

    ///
    /// \brief get the instance of the singleton, instancied it if necessary
    /// \return the instance
    ///
    static T* get()
    {
        if (isDefine())
        {
            s = new T;
        }
        return (static_cast<T*>(s));
    }

    static T* s;

protected:
    ///
    /// \brief it's impossible to build a singleton normaly
    ///
    Singleton()
    {
    }
    virtual ~Singleton()
    {
    }

};

template<typename T>
T* Singleton<T>::s = 0;

#endif /* SINGLETON_H_ */
