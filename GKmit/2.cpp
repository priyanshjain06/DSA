#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[1000];  //REVIEW char type 
    cin.getline(str, 1000); // Take full line as input

    char *word = strtok(str, " "); //REVIEW pointer 
    int lengths[100]; // To store word lengths
    int idx = 0;

    // Print words line by line and store their lengths
    while (word != NULL)
    {
        cout << word << endl;
        lengths[idx++] = strlen(word);
        word = strtok(NULL, " ");
    }

    // Print word lengths
    for (int i = 0; i < idx; i++)
    {
        cout << lengths[i] << endl;
    }

    return 0;
}

//REVIEW Process words individually	Count words, print each word on a new line

//REVIEW to get the next token in the string.
// "Continue from where you left off in the previous call.

//REVIEW Because C-style strings are arrays of characters, and in C/C++, a string is represented by a pointer to its first character.