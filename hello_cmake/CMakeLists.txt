cmake_minimum_required(VERSION 3.20)
PROJECT(hello_cpp)

SET(CMAKE_CXX_STANDARD 14)

MESSAGE(STATUS "THis is BINARY DIR" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "THis is SOURCE DIR" ${PROJECT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

ADD_SUBDIRECTORY(src bin)
#ADD_SUBDIRECTORY(lib lib_bin)

INSTALL(FILES README.md DESTINATION share/doc/hello_cpp)
INSTALL(DIRECTORY docs/ DESTINATION share/doc/hello_cpp)
INSTALL(PROGRAMS runhello.sh DESTINATION bin)
