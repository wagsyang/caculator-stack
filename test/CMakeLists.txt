add_executable(caculator_test test.cpp)

target_link_libraries(caculator_test expression)

add_test(
    NAME catch_test
    COMMAND $<TARGET_FILE:caculator_test> --success
)
