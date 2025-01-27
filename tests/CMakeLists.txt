add_executable(phone_reader_test phone_reader_test.cpp)

if(MSVC)
    target_compile_options(phone_reader_test PRIVATE /MD$<$<CONFIG:Debug>:d>)
endif()

target_link_libraries(phone_reader_test
    PRIVATE
    phone_reader_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(phone_reader_test) 