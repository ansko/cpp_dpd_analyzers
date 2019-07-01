cmake_minimum_required (VERSION 2.6) 
 

set (PROJECT dpd_tools) 


project (${PROJECT}) 

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


# CMAKE_CXX_FLAGS:
#
#   -std=c++17
#
#   -g0    no debug information
#   -g1    minimal debug information
#   -g     default debug information
#   -g3    maximal debug information
#
#   -lm    link math library
#
#   -DMACRO define MACRO:
#     DETAILED_OUTPUT      print a lot of log information
#     GENERAL_OUTPUT       print only main information
#     PARTIAL_DATAFILES    write out some incomplete datafiles (for debug mainly)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}\
            -Werror \
            -std=c++17 \
            -g \
            -lm \
            -O3 \
            -DDETAILED_OUTPUT \
            -DGENERAL_OUTPUT \
    ")
endif (CMAKE_COMPILER_IS_GNUCXX)

#https://stackoverflow.com/a/9328525/7927226
#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()



set (HEADERS
    src/py_string.hpp
    src/datafile_content.hpp
    src/platelets_distance.hpp
    src/structures.hpp
)


add_executable (test_exe ${HEADERS} main.cpp)

#target_link_libraries(isolated_parallel Threads::Threads)