set(translator_SRCS
    translator.h
    translator.cpp
)

# Declare the library
add_library(translator STATIC
    ${translator_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(translator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
