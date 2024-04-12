// File program that allows you to name your file lists 10 random number 0 - 100
// Does this 10 times per line for a total of 50 numbers. Formats the numbers neatly as well
// Lastly file name and information is outputted to console

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string yourname; //String variable

    cout << "Enter your name: " ;
    getline( cin >> ws, yourname); // White spaces between first and last name

    ofstream outputFile;
    outputFile.open(yourname + ".txt"); // File opens

    if(!outputFile.is_open()) // File opening error
    {
        cout << "Error! Unable to open the file. \n";
        return 1;
    }

    // RNG parameters
    unsigned seed = time(0);
    srand(seed);

    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;

    // RNG loop
    for(int c = 0; c < 50; c++)
    {
       int random_number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        outputFile << setw(3) << random_number; // Write random number to file


        if ((c + 1) % 10 == 0) // Newline after 10 numbers
            outputFile << endl;

        else
            outputFile << " "; // spaces added between lines
    }

    outputFile.close(); // File closes

    // Terminal output written to file
    cout << "File name is: " << yourname << ".txt" << endl;
    cout << "The information in this file is as follows: \n\n";

    ifstream inputFile;
    inputFile.open(yourname + ".txt"); // File opens and writes data to yourname.txt

    if(!inputFile.is_open())
    {
        cout << "Error! Unable to open the file." << endl; // File failed to be read
        return 1;
    }

    char ch;
    while (inputFile.get(ch))
    {
        cout << ch; //Output file content to console
    }

    inputFile.close(); //File closes

    return 0; // End of program

}