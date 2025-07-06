#include <iostream>
#include <sstream> //REVIEW - 
#include <vector>
using namespace std;

int main()
{
    string line;
    getline(cin, line); // Take full input line

    istringstream iss(line); // to split the string by white space : A B
    string word;
    vector<int> lengths;

    while (iss >> word) // input operator 
    {
        cout << word << endl;
        lengths.push_back(word.length());
    }

    for (int len : lengths)
    {
        cout << len << endl;
    }

    return 0;
}