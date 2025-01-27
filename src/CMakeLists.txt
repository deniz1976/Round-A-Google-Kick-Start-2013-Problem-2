add_library(phone_reader_lib
    phone_reader.cpp
    phone_reader.hpp
)

if(MSVC)
    target_compile_options(phone_reader_lib PRIVATE /MD$<$<CONFIG:Debug>:d>)
endif()

target_include_directories(phone_reader_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(phone_reader main.cpp)

if(MSVC)
    target_compile_options(phone_reader PRIVATE /MD$<$<CONFIG:Debug>:d>)
endif()

target_link_libraries(phone_reader PRIVATE phone_reader_lib) 