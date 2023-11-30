cmake_minimum_required(VERSION 3.26)
project(OS_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(OS_Project main.cpp
        "Command Functions/createFile.cpp"
        "Command Functions/deleteFile.cpp"
        "Command Functions/renameFile.cpp"
        "Command Functions/writeTxt.cpp"
        "Command Functions/modifyTxt.cpp"
        "Command Functions/removeTxt.cpp"
        "Command Functions/readFile.cpp"
        "Command Functions/copyFile.cpp"
        "Command Functions/functions.h"
        "Command Functions/testForTxt.cpp"
        "Command Functions/printCurrentDirectory.cpp")
