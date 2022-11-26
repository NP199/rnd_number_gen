cmake_policy(SET CMP0048 NEW)
project(rnd_number_generator VERSION 0.0.1)

cmake_minimum_required(VERSION 2.18)

include(FetchContent)

find_package(fmt QUIET)
if(NOT fmt_FOUND)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
    )
    FetchContent_MakeAvailable(fmt)
endif()
find_package(cli11 QUIET)
if(NOT cli11_FOUND)
    FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11
        GIT_TAG        main
    )
    FetchContent_MakeAvailable(cli11)
endif()


add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(
    ${PROJECT_NAME}
    CLI11::CLI11
    fmt::fmt
    )
