///
///  \file VectorReferenced.h
///  \brief std::vector with reference, to use SmartPtr
///  \date Feb 22, 2012
///  \author romain
///

#ifndef VECTORREFERENCED_H_
#define VECTORREFERENCED_H_

#include <vector>
#include "Referenced.h"
#include "ReferencedProtected.h"
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/serialization/vector.hpp>

///
/// \class VectorReferenced
/// \brief std::vector with reference, to be able to use SmartPtr
///
template<class T>
class VectorReferenced: public ReferencedProtected, public std::vector<T>
{
public:
    VectorReferenced()
    {
    }
    virtual ~VectorReferenced()
    {
    }
    VectorReferenced(T* begin, T* end) : std::vector<T>(begin, end)
    {
    }

//    ///
//    /// \brief serialize vector
//    /// \param ar and version is used by boost::serialization
//    /// \return void
//    ///
//    template <class Archive>
//    void serialize(Archive & ar, const unsigned int version)
//    {
//            ar & (std::vector<T>) *this;
//    }


};

#endif /* VECTORREFERENCED_H_ */
