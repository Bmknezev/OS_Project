#include "../functions.h"


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
            cout << "Data written successfully." << endl;
            cout << endl;

        }
        else {
            cout << "Failed to open the file." << endl;
        }

    }

}
