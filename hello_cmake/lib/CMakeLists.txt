SET(LIB_SRC hello.cpp)

ADD_LIBRARY(hello_static STATIC ${LIB_SRC})
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME hello)
# VERSION : library version, SOVERSION : API version
SET_TARGET_PROPERTIES(hello_static PROPERTIES VERSION 1.2 SOVERSION 1)
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)


ADD_LIBRARY(hello SHARED ${LIB_SRC})
SET_TARGET_PROPERTIES(hello PROPERTIES OUTPUT_NAME hello)
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# Install library

# install hello.h to <prefix>/include/hello directory
INSTALL(FILES hello.h DESTINATION include/hello)

# install two libraries: hello and hello_static
# hello is shared library(LIBRARY) to <prefix>/lib
# hello_static is static library(ARCHIVE) to <prefix>/lib
INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

