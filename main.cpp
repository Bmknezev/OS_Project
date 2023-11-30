#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

void createFile(string fileName ) {
    // Create File
    if ( fileName.find('.') != string::npos ) {
        ofstream MyFile(fileName);
        cout << fileName << " Created!" << endl;
    }
    else {
        cout << "Error: file does not have an extension" << endl;
    }
}

void deleteFile( string fileName ) {
    cout << "Deleting " << fileName << endl;
    remove(fileName.c_str()); // delete file
}

void renameFile( string oldFileName, string newFileName ) {
    cout << "Renaming " << oldFileName << " to " << newFileName << endl;
    rename(oldFileName.c_str(), newFileName.c_str()); // rename file
}

bool testForTxt(string fileName) {
    if (fileName.find(".txt") != string::npos) {
        return true;
    }
    else {
        return false;
    }
};

void writeTxt(string fileName) {
    if (testForTxt(fileName)) {
        ofstream outputFile;
        outputFile.open(fileName, ios::app);
        cout << endl;
        if (outputFile.is_open()) {
            string newData;

            cout << "Enter the data to write (^X to end): ";
            //keep getting input until ^X is entered
            string s;
            while (getline( std::cin, s ))
            {
                // Find ^X in s
                auto n = s.find( '\x18' );
                if (n != s.npos) s = s.substr( 0, n );

                    outputFile << s << endl;

                // If ^C was found in s, we're done reading input from user
                if (n != s.npos) break;
            }

            outputFile.close();
            cout << "Data appended successfully." << endl;
            cout << endl;

        }
        else {
            cout << "Failed to open the file." << endl;
        }

    }

}

void addTextToLocation(string fileName) {
    if (!testForTxt(fileName)) { return; }
    int numberOfCharacters = 0;
    string newData;

    cout << "How many characters in would you like to insert the data? : ";
    cin >> numberOfCharacters;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the data to append: ";

    getline(cin, newData);

    string temp;
    ostringstream readFromFile;
    ifstream readFile(fileName);
    for (int i = 0; i < numberOfCharacters; i++) {
        readFromFile << char(readFile.get() );
    }
    readFromFile << newData;
    readFile >> temp;
    readFromFile << temp;
    ofstream out(fileName);
    temp = readFromFile.str();
    out << temp;
    out.close();
}

void removeText(string fileName) {
    if (testForTxt(fileName)) {
        ofstream out(fileName);
        out.close();
    }

}

void readFile(string fileName) {
    if ( !testForTxt(fileName) ) { return; }
    ifstream readFile(fileName);
    string data;

    ostringstream sstr;
    sstr << readFile.rdbuf();
    data = sstr.str();
    //readFile >> data;
    int strLen = data.length();
    int numberOfLinesPerPage;
    cout << "How many lines per page? : ";
    cin >> numberOfLinesPerPage;
    int counter = 0;
    for (int i = 0; i < strLen; i++) {
        if ( data[i] == '\n' ) {
            counter++;
        }
    }
    int countLines = 0;
    for (int i = 0; i < strLen; i++) {
        cout << data[i];
        if (data[i] == '\n') {
            countLines++;
        }
        if (countLines >= numberOfLinesPerPage) {
            string temp;
            cin.ignore();
            countLines = 0;
        }

    }
}

void copyFile(string oldFile, string newFile) {
    if (!testForTxt(oldFile)) { return; }
    ifstream readFile(oldFile);
    string data;

    ostringstream sstr;
    sstr << readFile.rdbuf();
    data = sstr.str();

    ofstream writeFile(newFile);
    writeFile << data;
}


int main() {

    string choice;
    cout << "Welcome to the File Manager" << endl;

    do {
        //functions, new, remove, rename, write, modify, clear, read, copy, help, exit
        cin >> choice;

        if (choice == "new") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            createFile(fileName);
        }
        else if (choice == "remove") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            deleteFile(fileName);
        }
        else if (choice == "rename") {
            string oldFileName;
            string newFileName;
            cout << "Enter the name of the file to rename: ";
            cin >> oldFileName;
            cout << "Enter the new name of the file: ";
            cin >> newFileName;
            renameFile(oldFileName, newFileName);
        }
        else if (choice == "write") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            writeTxt(fileName);
        }
        else if (choice == "modify") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            addTextToLocation(fileName);
        }
        else if (choice == "clear") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            removeText(fileName);
        }
        else if (choice == "read") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            readFile(fileName);
        }
        else if (choice == "copy") {
            string oldFile;
            string newFile;
            cout << "Enter the name of the file to copy: ";
            cin >> oldFile;
            cout << "Enter the name of the new file: ";
            cin >> newFile;
            copyFile(oldFile, newFile);
        }
        else if (choice == "help") {
            cout << "Commands:" << endl
            << "\tCreate a new file: new" << endl
            << "\tDelete a file: remove" << endl
            << "\tRename a file: rename" << endl
            << "\tCopy a file: copy" << endl
            << "\tMove a file from one directory to another: move" << endl
            << "\tAppend text to the end of a text file: write" << endl
            << "\tInsert text into a text file: modify" << endl
            << "\tRemove all text in a text file: clear" << endl
            << "\tRead all text from a text file: read" << endl
            << "\tGet help with using a command: <command> help" << endl
            << "\tExit the POFM: exit" << endl;
        }
        else if (choice == "exit") {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }

    } while (choice != "exit");

}