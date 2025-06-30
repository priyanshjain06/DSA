#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    string fullText;

    cout << "Enter multiple lines (enter an empty line to finish):" << endl;

    while (getline(cin, input)) // REVIEW -
    {
        if (input.empty()) // REVIEW -
        {
            break;
        }
        fullText += input + '\n'; // FIXME -
    }

    cout << "\n You entered:\n"
         << fullText << endl; //REVIEW - 

    return 0;
}
