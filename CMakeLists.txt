cmake_minimum_required(VERSION 3.26)
project(Algorithm_for_Skyline_Queries)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(Algorithm_for_Skyline_Queries main.cpp
        "data set.cpp"
        "skyline calculator.cpp"
        "graphic creation.cpp")

target_link_libraries(Algorithm_for_Skyline_Queries sfml-graphics)

