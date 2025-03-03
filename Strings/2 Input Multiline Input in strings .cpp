#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    string fullText;

    cout << "Enter multiple lines (enter an empty line to finish):" << endl;

    // Loop to read multiple lines
    while (getline(cin, input)) // REVIEW -
    {
        // Stop if the user enters an empty line
        if (input.empty()) // REVIEW -
        {
            break;
        }
        // Append the line to fullText, adding a newline
        fullText += input + '\n'; // REVIEW -
    }

    cout << "\n You entered:\n"
         << fullText << endl;

    return 0;
}
