cmake_minimum_required(VERSION 3.10)

project(AoC_2021_C C)

set(CMAKE_COLOR_DIAGNOSTICS ON)

include_directories(${AOC_UTIL_INSTALL}/include)

link_directories(${AOC_UTIL_INSTALL}/lib/)

add_executable(
    aoc
    src/main.c
    src/day1.c
    src/day2.c
    src/day3.c
    src/day4.c
    src/day5.c
)

target_link_libraries(aoc aoc_util pthread)

set(CMAKE_C_FLAGS_RELEASE "-O3")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
