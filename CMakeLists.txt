cmake_minimum_required(VERSION 3.26)
project(OS_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(OS_Project main.cpp
        "Command Functions/createFile.cpp"
        "Command Functions/deleteFile.cpp"
        "Command Functions/renameFile.cpp"
        "Command Functions/Text Files/writeTxt.cpp"
        "Command Functions/Text Files/modifyTxt.cpp"
        "Command Functions/Text Files/removeTxt.cpp"
        "Command Functions/Text Files/readFile.cpp"
        "Command Functions/copyFile.cpp"
        "Command Functions/functions.h"
        "Command Functions/Text Files/testForTxt.cpp"
        "Command Functions/Traversal/printCurrentDirectory.cpp"
        "Command Functions/Traversal/createFolder.cpp"
        "Command Functions/Traversal/enterSubdirectory.cpp"
        "Command Functions/Traversal/exitSubdirectory.cpp"
        "Command Functions/Traversal/deleteFolder.cpp"
        "directory 1/blupt directory/blupt.cpp"
)
