include_directories(./include)
file (GLOB
	sources_files
	src/*.cpp)
add_library(tools STATIC ${sources_files})



