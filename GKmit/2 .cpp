#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[1000];  //REVIEW char type 
    cin.getline(str, 1000); // Take full line as input

    char *word = strtok(str, " ");
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
