SET(SRC_LIST main.cpp)
ADD_EXECUTABLE(hello_main ${SRC_LIST})

# Use Library
ADD_EXECUTABLE(call_lib call_lib.cpp)
INCLUDE_DIRECTORIES(/usr/local/include/hello)

LINK_DIRECTORIES(/usr/local/lib)

TARGET_LINK_LIBRARIES(call_lib libhello.a hello libhello libhello.dylib)
