#include <iostream>
#include <string>
#include "Command Functions/functions.h"

using namespace std;

int main() {
    string choice;

    //path currentPath = current_path();
    cout << "Welcome to the File Manager" << endl;

    string blipto = "root";
    //printCurrentDirectory();

    createFolder(blipto);
    enterSubdirectory(blipto);
    printCurrentDirectory();
    filesystem::path root = filesystem::current_path();

    do {
        //get user input
        getline(cin, choice);

        //first check for help command
        if(choice.find("help") != string::npos) {
            //check for specific help command
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
            } else if (choice.find("blipto") != string::npos) {
                cout << "navigates to a subdirectory" << endl << "usage: blipto <subdirectory name (leave empty to navigate back)>" << endl;
            } else if (choice.find("list") != string::npos) {
                cout << "lists all files in current directory" << endl << "usage: list" << endl;
            } else if (choice.find("make") != string::npos) {
                cout << "creates a new folder" << endl << "usage: make <folder name>" << endl;
            } else if (choice.find("exit") != string::npos) {
                cout << "exits the program" << endl << "usage: exit" << endl;
            } else if(choice.find("blango") != string::npos) {
                cout << "deletes a folder" << endl << "usage: blango <folder name>" << endl;
            }
            else
                cout << "new" << endl
                     << "remove" << endl
                     << "rename" << endl
                     << "write" << endl
                     << "modify" << endl
                     << "clear" << endl
                     << "read" << endl
                     << "copy" << endl
                     << "blipto" << endl
                     << "list" << endl
                     << "make" << endl
                     << "blango" << endl
                     << "exit" << endl;


        }
        //check for new command
        else if(choice.find("new") != string::npos){
            //erase the command from the string
            choice.erase(0, 4);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                createFile(choice);

        }
        //check for remove command
        else if(choice.find("remove") != string::npos){
            //erase the command from the string
            choice.erase(0, 7);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                deleteFile(choice);

        }
        //check for rename command
        else if(choice.find("rename") != string::npos){
            string oldFileName;
            string newFileName;
            //get old file name and new file name from choice string
            oldFileName = choice.substr(7, choice.find(' ', 7) - 7);
            newFileName = choice.substr(choice.find(' ', 7) + 1);
            //check if the user gave the file names
            if(oldFileName.empty() || newFileName.empty())
                cout << "Error: no file name given" << endl;
            else
             renameFile(oldFileName, newFileName);
        }
        //check for write command
        else if(choice.find("write") != string::npos){
            //erase the command from the string
            choice.erase(0, 6);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                writeTxt(choice);
        }
        //check for modify command
        else if(choice.find("modify") != string::npos){
            //erase the command from the string
            choice.erase(0, 7);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                modifyTxt(choice);
        }
        //check for clear command
        else if(choice.find("clear") != string::npos){
            //erase the command from the string
            choice.erase(0, 6);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                removeText(choice);
        }
        //check for read command
        else if(choice.find("read") != string::npos){
            //erase the command from the string
            choice.erase(0, 5);
            //check if the user gave a file name
            if(choice.empty())
                cout << "Error: no file name given" << endl;
            else
                readFile(choice);
        }
        //check for copy command
        else if(choice.find("copy") != string::npos){
            string oldFile;
            string newFile;
            //get old file name and new file name from choice string
            oldFile = choice.substr(5, choice.find(' ', 5) - 5);
            newFile = choice.substr(choice.find(' ', 5) + 1);
            //check if the user gave the file names
            if(oldFile.empty() || newFile.empty())
                cout << "Error: no file name given" << endl;
            else
                copyFile(oldFile, newFile);
        }else if(choice.find("blipto") != string::npos) {
            //navigate to subdirectory
            choice.erase(0, 7);
            if(choice.empty()) {
                try {
                    exitSubdirectory(root);
                } catch (const exception& e) {
                    cerr << "Error in exitSubdirectory: " << e.what() << endl;
                }
            }
            else
                enterSubdirectory(choice);
        }else if(choice.find("list") != string::npos) {
            //list all files in current directory
            printCurrentDirectory();
        }else if(choice.find("make") != string::npos) {
            //create new folder
            choice.erase(0, 5);
            if (choice.empty())
                cout << "Error: no folder name given" << endl;
            else
                createFolder(choice);
        }else if(choice.find("exit") != string::npos) {
            //exit program
            cout << "Exiting program..." << endl;
        }else if(choice.find("blango") != string::npos) {
            //delete folder
            choice.erase(0, 7);
            if (choice.empty())
                cout << "Error: no folder name given" << endl;
            else
                deleteFolder(choice);
        }
        else{
            cout << "Error: invalid command" << endl;
        }

        //loop until command is exit
    } while (choice != "exit");

}