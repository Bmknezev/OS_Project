
#ifndef OS_PROJECT_FUNCTIONS_H
#define OS_PROJECT_FUNCTIONS_H
#endif //OS_PROJECT_FUNCTIONS_H

#include <string>
#include <sstream>
#include <limits>
#include <fstream>
#include <cstdio>
#include <iostream>

using namespace std;

void copyFile(string oldFile, string newFile);
void createFile(string fileName);
void deleteFile(string fileName);
void renameFile(string oldFileName, string newFileName);
void writeTxt(string fileName);
void modifyTxt(string fileName);
void removeText(string fileName);
void readFile(string fileName);
bool testForTxt(string fileName);

    // traversal

void printCurrentDirectory();
bool enterSubdirectory(string& subfolderName);
bool exitSubdirectory();
bool createFolder(string& folderName);
bool deleteFolder(string& folderName);