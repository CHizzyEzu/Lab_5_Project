// File program that allows you to name your file lists 10 random number 0 - 100
// Does this 10 times per line for a total of 50 numbers. Formats the numbers neatly as well
// The file name and information is outputted to console
// Lastly the min, max, average, and sum of all the numbers are outputted at the end of the program

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

    outputFile << yourname << endl;

    // RNG parameters
    unsigned seed = time(0);
    srand(seed);

    const int MIN_VALUE = 0;
    const int MAX_VALUE = 100;

    // RNG loop
    for(int c = 0; c < 50; c++)
    {
       int random_number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        outputFile << setw(3) << random_number; // Write random number to file


        if ((c + 1) % 10 == 0) // Newline after 10 numbers
            outputFile << endl;
    }

    outputFile.close(); // File closes

    ifstream inputFile;
    inputFile.open(yourname + ".txt"); // File opens and writes data to yourname.txt

    if(!inputFile.is_open())
    {
        cout << "Error! Unable to open the file for reading." << endl; // File failed to be read
        return 1;
    }

    string nameFromFile;
    getline(inputFile, nameFromFile);
    cout << "Name from file: " << nameFromFile << endl;

    // Read and display the numbers , calculate sum, min, max, and average
    int sum = 0;
    int min = 0;
    int max = 0;
    int count = 0;

    int number; //

    // Loops through numbers in two's, counts the numbers and adds them together
    while(inputFile >> number)
    {
        cout << setw(3) << number << " ";
        sum += number;
        if(number < min) min = number;
        if(number > max) max = number;
        count++;
        if(count % 2 == 0) cout << endl; // Start a new line every 2 numbers

    }

    inputFile.close(); //File closes

    // Holds a decimal value for the average
    double average = static_cast<double>(sum) / count;

    // Display statistics
    cout << "\n\nTotal: " << sum << endl;
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;

    return 0; // End of program

}