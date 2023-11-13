#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

void createFile( std::string fileName ) {
    // Create File
    if ( fileName.find(".") == true ) {
        std::ofstream MyFile(fileName);
        std::cout << fileName << " Created!" << std::endl;
    }
    else {
        std::cout << "Error: file does not have an extension" << std::endl;
    }
}

void deleteFile( std::string fileName ) {
    char* str = (char)malloc( fileName.size() sizeof(char));
    strcpy(str, fileName.c_str());
    std::remove(str); // delete file
}

void renameFile( std::string oldFileName, std::string newFileName ) {
    char* oldFile = (char)malloc(oldFileName.size() sizeof(char));
    strcpy(oldFile, oldFileName.c_str());

    char* newFile = (char)malloc(newFileName.size() sizeof(char));
    strcpy(newFile, newFileName.c_str());

    rename(oldFile, newFile);
}

void copyFile(std::string originalFile, std::string newFile) {
    std::ifstream  src(originalFile, std::ios::binary);
    std::ofstream  dst(newFile, std::ios::binary);

    dst << src.rdbuf();
}