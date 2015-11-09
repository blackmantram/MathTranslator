set(Main_SRCS
    main.cpp
)

add_executable(mathTranslator
    ${Main_SRCS}
)

install(TARGETS mathTranslator DESTINATION bin)
