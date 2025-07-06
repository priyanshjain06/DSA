#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    string input;
    getline(cin, input); // Read full line including spaces

    istringstream iss(input);
    string word;
    unordered_map<string, int> freq;
    vector<string> order; // to preserve original order

    // Count frequencies
    while (iss >> word)
    {
        if (freq[word] == 0)
            order.push_back(word); // Store first-time seen word
        freq[word]++;
    }

    // Check and print non-repeating words
    bool found = false;
    for (const string &w : order)
    {
        if (freq[w] == 1)
        {
            cout << w << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No non-repeating words found.";
    }

    cout << endl;
    return 0;
}


//SECTION -  another method 

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    string input;
    getline(cin, input); // Read full line
    unordered_map<string, int> freq;
    vector<string> order;

    string word = "";
    for (char ch : input) {
        if (ch == ' ') {
            if (!word.empty()) {
                if (freq[word] == 0)
                    order.push_back(word);
                freq[word]++;
                word.clear(); // reset for next word
            }
        } else {
            word += ch; // build the word
        }
    }

    // Handle the last word (if any)
    if (!word.empty()) {
        if (freq[word] == 0)
            order.push_back(word);
        freq[word]++;
    }

    // Print non-repeating words
    bool found = false;
    for (string &w : order) {
        if (freq[w] == 1) {
            cout << w << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No non-repeating words found.";
    }

    cout << endl;
    return 0;
}
