cmake_minimum_required(VERSION 3.2)

set(CMAKE_PATCH_VERSION "1" CACHE "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

#option
configure_file(version.h.in version.h)

add_executable(helloworld main.cpp)
add_library(helloworld_library lib.cpp)

set_target_properties(helloworld helloworld_library PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

