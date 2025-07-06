#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string line;
    getline(cin, line); // Take full input line

    istringstream iss(line);
    string word;
    vector<int> lengths;

    while (iss >> word)
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