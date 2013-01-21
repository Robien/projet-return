#version 2.6 de CMake Requise
cmake_minimum_required(VERSION 2.6)

IF(WIN32)
	set (BOOST_ROOT ./boost_1_52_0/stage)
	set (BOOST_LIBRARYDIR ./boost_1_52_0/stage/lib)
	message("vive les pommes")
ENDIF(WIN32)


if(UNIX)
	if(EXISTS "/usr/local/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/local/share/OGRE/samples/Common/include/") # We could just *assume* that developers uses this basepath : /usr/local

	elseif(EXISTS "/usr/lib/OGRE/cmake")

	  set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
	  set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/") # Otherwise, this one

	else ()
	  message(SEND_ERROR "Failed to find module path.")
	endif(EXISTS "/usr/local/lib/OGRE/cmake")
endif(UNIX)


#nom du projet
project (return)
set(CMAKE_CXX_FLAGS "-march=native ")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wunused-label")
SET(CMAKE_CXX_FLAGS_DEBUG  "-Wall -g -O3")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
SET(CMAKE_USE_RELATIVE_PATHS "ON")

###Set Configuration Type
  SET(CMAKE_BUILD_TYPE RelWithDebInfo)
IF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE RelWithDebInfo)
ENDIF(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
add_definitions( -DBUILD_TYPE )
endif (${CMAKE_BUILD_TYPE} STREQUAL Debug)


#ogre
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)
 
if(NOT OIS_FOUND)
	message(SEND_ERROR "Failed to find OIS.")
endif()


# boost
SET(Boost_USE_STATIC_LIBS ON)

SET(Boost_USE_MULTITHREADED ON)
add_definitions(-DBOOST_ALL_NO_LIB)

include(FindBoost)
find_package(
        Boost
        1.38.0
        REQUIRED filesystem system program_options thread
)
link_directories(${Boost_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(
   ${Boost_INCLUDE_DIRS}
)
include_directories( ${OIS_INCLUDE_DIRS}
	${OGRE_INCLUDE_DIRS}
	${OGRE_SAMPLES_INCLUDEPATH}
)


#ajout du répertoire de sources
add_subdirectory(sources)



