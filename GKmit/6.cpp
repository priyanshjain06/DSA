#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int getArrangementRank(const string &sequence)
{
    // Step 1: Define company ranking
    unordered_map<string, int> rankMap = {
        {"Ford", 1},
        {"Toyota", 2},
        {"Tata", 3}};

    // Step 2: Split the sequence into words
    vector<string> companies;
    istringstream iss(sequence);
    string company;
    while (iss >> company)
    {
        companies.push_back(company);
    }

    // Step 3: Apply ranking formula
    int n = companies.size();
    int totalRank = 0;

    for (int i = 0; i < n; ++i)
    {
        int power = n - 1 - i;
        int rank = rankMap[companies[i]];
        totalRank += rank * pow(3, power); // compound operator
    }

    return totalRank;
}