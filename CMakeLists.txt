cmake_minimum_required(VERSION 3.0.0)
project(Library VERSION 0.1.0)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("/include"
                "/src"
                "/doctest")

add_executable(library "library.cpp"
                "src/Commands.cpp"
                "src/String.cpp"
                "src/Draw.cpp"
                "src/User.cpp"
                "src/Book.cpp"
                "src/UserDB.cpp"
                "src/LoginUser.cpp"
                "src/DeleteUser.cpp"
                "src/AddUser.cpp"
                "src/ViewUsers.cpp"
                "src/BookDB.cpp"
                "src/AddBook.cpp"
                "src/ViewBook.cpp"
                "src/DeleteBook.cpp"
                "src/SearchBook.cpp"
                "src/SortBooks.cpp"
                "src/InputHandle.cpp"
                "src/OpenDB.cpp"
                "src/SaveDB.cpp"
                "src/BookFiles.cpp"
                "src/UserFiles.cpp"
                )

add_executable(test "tests/main.cpp"
                "doctest/doctest.h") 

add_executable(string "Tests/string.cpp"
                "include/String.h"
                "src/String.cpp"
                "doctest/doctest.h")

#add_executable(vector "Tests/vector.cpp"
 #               "include/Vector.h"
  #              "include/String.h"
   #             "src/String.cpp"
    #            "doctest/doctest.h")
#