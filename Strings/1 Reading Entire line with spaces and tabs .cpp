#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;

    cout << "Enter a line with spaces or tabs: ";
    // REVIEW
    getline(cin, input); // reads the entire line, including spaces and tabs

    // REVIEW to read multiple lines with spaces and tabs !
    while (getline(cin, input))
    {
        input = input + '\n';
    }
    cout << "You entered: " << input << endl;

    return 0;
}