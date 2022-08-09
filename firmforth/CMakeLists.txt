cmake_minimum_required(VERSION 2.8.12)
project(firmforth LANGUAGES C CXX)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_C_STANDARD 99)

include_directories(../libfirm/include)

add_executable(
    firmforth
    firmforth.h
    firmforth.c
    mangle.h
    mangle.c
    )

set(LIB_DIR "/home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm")
target_include_directories(firmforth PUBLIC ${LIB_DIR}/gen/include/libfirm)
target_link_directories(firmforth PUBLIC ${LIB_DIR})
target_link_libraries(firmforth PUBLIC libfirm.a dl m)

