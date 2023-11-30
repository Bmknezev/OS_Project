#include <iostream>
#include <string>
#include "Command Functions/functions.h"

using namespace std;

int main() {
    string choice;

    //path currentPath = current_path();
    //cout << "Welcome to the File Manager" << endl << currentPath << endl;

    printCurrentDirectory();

    do {
        //functions, new, remove, rename, write, modify, clear, read, copy, help, exit
        getline(cin, choice);


        if(choice.find("help") != string::npos){
            if (choice.find("new") != string::npos) {
                cout << "creates a new file" << endl << "usage: new <filename>" << endl;
            } else if (choice.find("remove") != string::npos) {
                cout << "deletes a file" << endl << "usage: remove <filename>" << endl;
            } else if (choice.find("rename") != string::npos) {
                cout << "renames a file" << endl << "usage: rename <old filename> <new filename>" << endl;
            } else if (choice.find("write") != string::npos) {
                cout << "writes text to a file" << endl << "usage: write <filename>" << endl;
            } else if (choice.find("modify") != string::npos) {
                cout << "inserts text into a file at a specific location" << endl << "usage: modify <filename>" << endl;
            } else if (choice.find("clear") != string::npos) {
                cout << "removes all text from a file" << endl << "usage: clear <filename>" << endl;
            } else if (choice.find("read") != string::npos) {
                cout << "reads all text from a file" << endl << "usage: read <filename> <number of lines per page>" << endl;
            } else if (choice.find("copy") != string::npos) {
                cout << "copies a file" << endl << "usage: copy <old filename> <new filename>" << endl;
            }else{
                cout << "new" << endl
                     << "remove" << endl
                     << "rename" << endl
                     << "write" << endl
                     << "modify" << endl
                     << "clear" << endl
                     << "read" << endl
                     << "copy" << endl
                     << "help" << endl
                     << "exit" << endl;
            }
        }else if(choice.find("new") != string::npos){
            choice.erase(0, 4);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                createFile(choice);
        }else if(choice.find("remove") != string::npos){
            choice.erase(0, 7);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                deleteFile(choice);
        }else if(choice.find("rename") != string::npos){
            string oldFileName;
            string newFileName;
            oldFileName = choice.substr(7, choice.find(" ", 7) - 7);
            newFileName = choice.substr(choice.find(" ", 7) + 1);
            if(oldFileName.empty() || newFileName.empty())
                cout << "Error: no file name given" << endl;
            else
             renameFile(oldFileName, newFileName);
        }
        else if(choice.find("write") != string::npos){
            choice.erase(0, 6);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                writeTxt(choice);
        }
        else if(choice.find("modify") != string::npos){
            choice.erase(0, 7);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                modifyTxt(choice);
        }
        else if(choice.find("clear") != string::npos){
            choice.erase(0, 6);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                removeText(choice);
        }
        else if(choice.find("read") != string::npos){
            choice.erase(0, 5);
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                readFile(choice);
        }
        else if(choice.find("copy") != string::npos){
            string oldFile;
            string newFile;
            oldFile = choice.substr(5, choice.find(" ", 5) - 5);
            newFile = choice.substr(choice.find(" ", 5) + 1);
            if(oldFile.empty() || newFile.empty())
                cout << "Error: no file name given" << endl;
            else
                copyFile(oldFile, newFile);
        }

    } while (choice != "exit");

}