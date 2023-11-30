#include "functions.h"



void modifyTxt(string fileName) {
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
