cmake_minimum_required(VERSION 3.17)

project(Library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include"
                "src")

add_executable(library "library.cpp"
                "src/Commands.cpp"
                "src/String.cpp"
                )