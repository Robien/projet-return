///
///  \file Options.h
///	 \brief  manage options from command line and file
///  \date Mar 1, 2012
///  \author romain
///

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <iostream>
#include <boost/program_options.hpp>
#include "Singleton.h"
#include <boost/thread/thread.hpp>

///
/// \class Options
/// \brief manage options from command line and file
///
class Options: public Singleton<Options>
{
public:
    ///
    /// \brief constructor
    ///
    Options();
    ///
    /// \brief destructor
    ///
    virtual ~Options();

public:
    ///
    /// \brief set arg and argc from main parameters
    /// \param argv
    /// \param argc
    /// \return void
    ///
    void setCommandLineOptions(int argc, char** argv);

public:
    ///
    /// \brief check if the command line have this arguments
    /// \param arg to check
    /// \return true if arg exist
    ///
    bool isSet(std::string arg);

    ///
    /// \brief return the value of the arguments
    /// \param arg your looking for
    /// \return value of the arg
    ///
    template<typename T>
    T getValue(std::string arg)
    {
        if (_vm.count(arg))
        {
            return _vm[arg].as<T>();
        }
        else
        {
            std::cerr << "Error in command line, please add a " << arg << "argument" << std::endl;
            helpAndExit();
            return NULL;
        }
    }
    ///
    /// \brief print help and exit program
    /// \return void
    ///
    void helpAndExit();
    ///
    /// \brief choose between value of args in command line if exist and defaultValue
    /// \param arg : arg we are looking for
    /// \param defaultValue : if arg not define, it's returned
    /// \return value(arg) or defaultValue
    ///
    template<typename T>
    T selectIfDefine(std::string arg, T defaultValue)
    {
        if (isSet(arg))
        {
            return getValue<T>(arg);
        }
        else
        {
            return defaultValue;
        }
    }


    void lock()
    {
        m.lock();
    }
    void unlock()
    {
        m.unlock();
    }


private:

    boost::mutex m;

    boost::program_options::variables_map _vm;
    boost::program_options::options_description* _desc;

};

#endif /* OPTIONS_H_ */
