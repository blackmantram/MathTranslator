set(Main_SRCS
    main.cpp
)

add_executable(mathTranslator
    ${Main_SRCS}
)

target_link_libraries(mathTranslator
    translator
)

install(TARGETS mathTranslator DESTINATION bin)
