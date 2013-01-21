///
///  \file Options.cpp
///	 \brief manage options from command line and file
///  \date Mar 1, 2012
///  \author romain
///

#include "Options.h"

Options::Options()
{
    _desc = new boost::program_options::options_description("Allowed options");
    _desc->add_options()
    ("help,h", "produce help message")
    ("jobs,j", boost::program_options::value<unsigned int>(), "number of jobs to run")
    ("camp", "use a .camp importer")
    ("csv", "use a .csv importer")
    ("file", boost::program_options::value<std::string>(), "file to open with camp or csv importer")
    ("maj_offset", boost::program_options::value<unsigned int>(), "how many curves before update IHM")
    ("exact,e", "force exact value at every time (at the end, values are always exact) it's a bit slower")
    ("brutal_end", "kill all process at the end of attack")
    ("max-size-buffer,b", boost::program_options::value<unsigned int>(), "maximum size of buffer");
//    ("client,c", "become a client (incompatible with --server)")
//    ("server,s", "become a server (incompatible with --client) ")
//    ("port,p", boost::program_options::value<unsigned int>(), "port of server")
//    ("ip", boost::program_options::value<std::string>(), "ip of server")
//    ("bto", boost::program_options::value<unsigned int>(),  "num of byte to attack")
}

Options::~Options()
{
}

void Options::setCommandLineOptions(int argc, char** argv)
{

    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, *_desc), _vm);

    boost::program_options::notify(_vm);

    if (_vm.count("help"))
    {
        helpAndExit();
    }
}

bool Options::isSet(std::string arg)
{
    return _vm.count(arg);
}

void Options::helpAndExit()
{
    std::cout << *_desc << std::endl;
    exit(0);
}
