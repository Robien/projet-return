add_subdirectory(tools)
include_directories(tools)
include_directories(tools/include)



#create exe for return
add_executable(../bin/return executables/main.cpp)


#link configuration
target_link_libraries(../bin/return ${Boost_LIBRARIES} )
target_link_libraries(../bin/return ${OGRE_LIBRARIES} ${OIS_LIBRARIES})
target_link_libraries(../bin/return pthread)
target_link_libraries(../bin/return tools)

