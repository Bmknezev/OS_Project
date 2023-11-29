#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void appendTxt(string fileName) {
    if (testForTxt(fileName)) {
        ofstream outputFile;
        outputFile.open(fileName, ios::app);
        cout << endl;
        if (outputFile.is_open()) {
            string newData;

            cout << "Enter the data to append: ";
            getline(cin, newData);
            outputFile << newData << endl;
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

    int choice;

    do {
        cout << "File Manager" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Delete File" << endl;
        cout << "3. Rename File" << endl;
        cout << "4. Append Text" << endl;
        cout << "5. Add Text to Location" << endl;
        cout << "6. Remove Text" << endl;
        cout << "7. Read File" << endl;
        cout << "8. Copy File" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string fileName;
        string newFileName;
        switch (choice) {
        case 1:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            createFile(fileName);
            break;
        case 2:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            deleteFile(fileName);
            break;
        case 3:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            cout << "Enter the new file name: ";
            getline(cin, newFileName);
            renameFile(fileName, newFileName);
            break;
        case 4:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            appendTxt(fileName);
            break;
        case 5:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            addTextToLocation(fileName);
            break;
        case 6:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            removeText(fileName);
            break;
        case 7:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            readFile(fileName);
            break;
        case 8:
            cout << "Enter the file name: ";
            getline(cin, fileName);
            cout << "Enter the new file name: ";
            getline(cin, newFileName);
            copyFile(fileName, newFileName);
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << endl;
    } while (choice != 9);

}