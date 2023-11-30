#include "../functions.h"



void modifyTxt(string fileName) {
    if (!testForTxt(fileName)) { return; }
    int numberOfCharacters = 0;
    string newData;

    cout << "How many characters in would you like to insert the data? : ";
    cin >> numberOfCharacters;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the data to append: ";

    string temp;
    ostringstream readFromFile;
    ifstream readFile(fileName);
    for (int i = 0; i < numberOfCharacters; i++) {
        if(readFile.eof())
            break;
        readFromFile << char(readFile.get() );
    }
    while (getline( std::cin, newData ))
    {
        // Find ^X in s
        auto n = newData.find( '\x18' );
        if (n != newData.npos) newData = newData.substr( 0, n );

        readFromFile << newData << endl;

        // If ^C was found in s, we're done reading input from user
        if (n != newData.npos) break;
    }
    while(!readFile.eof())
        readFromFile << char(readFile.get());

    //readFromFile << temp;
    ofstream out(fileName);
    temp = readFromFile.str();
    out << temp;
    out.close();
}
