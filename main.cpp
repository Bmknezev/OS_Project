#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


void createFile( std::string fileName ) {
    // Create File
    if ( fileName.find('.') != std::string::npos ) {
        std::ofstream MyFile(fileName);
        std::cout << fileName << " Created!" << std::endl;
    }
    else {
        std::cout << "Error: file does not have an extension" << std::endl;
    }
}

void deleteFile( std::string fileName ) {
    std::cout << "Deleting " << fileName << std::endl;
    std::remove(fileName.c_str()); // delete file
}

void renameFile( std::string oldFileName, std::string newFileName ) {
    std::cout << "Renaming " << oldFileName << " to " << newFileName << std::endl;
    std::rename(oldFileName.c_str(), newFileName.c_str()); // rename file
}

void copyFile(std::string originalFile, std::string newFile){
}



int main() {
    std::string fileName = "test.txt";
    std::string newFileName = "test2.txt";
    createFile(fileName);
    renameFile(fileName, newFileName);
    //deleteFile(newFileName);
    return 0;
}