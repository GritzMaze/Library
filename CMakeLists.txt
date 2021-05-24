cmake_minimum_required(VERSION 3.0.0)
project(Library VERSION 0.1.0)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("/include"
                "/src")

add_executable(library "library.cpp"
                "src/Commands.cpp"
                "src/String.cpp"
                "src/Draw.cpp"
                "src/User.cpp"
                "src/Book.cpp"
                )
