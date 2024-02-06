cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "3" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

option(WITH_GTEST "Whether to build Google test")
configure_file(version.h.in version.h)

add_executable(helloworld main.cpp)
add_library(helloworld_library lib.cpp)

set_target_properties(helloworld helloworld_library PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

#Чтобы нашелся файл version.h
target_include_directories(helloworld_library
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld PRIVATE
    helloworld_library
)

if(WITH_GTEST)
    find_package(GTest REQUIRED)
    add_executable(test_version test_version.cpp)

    set_target_properties(test_version PROPERTIES
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_version PRIVATE
     ${GTEST_LIBRARIES}
     ${CMAKE_THREAD_LIBS_INIT}
     helloworld_library)

endif()

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)