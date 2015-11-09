file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(translationTest ${SRCS})

TARGET_LINK_LIBRARIES(translationTest
	translator
    libgtest
    libgmock
)

add_test(NAME translationTest
         COMMAND translationTest)
