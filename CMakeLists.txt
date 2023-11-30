cmake_minimum_required(VERSION 3.26)
project(OS_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(OS_Project main.cpp
        createFile.cpp
        deleteFile.cpp
        renameFile.cpp
        writeTxt.cpp
        modifyTxt.cpp
        removeTxt.cpp
        readFile.cpp
        copyFile.cpp
        functions.h
        testForTxt.cpp)
