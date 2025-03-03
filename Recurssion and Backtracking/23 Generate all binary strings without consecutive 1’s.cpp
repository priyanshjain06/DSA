#include <iostream>
#include <vector>
using namespace std;

void generateBinaryStrings(int k, string current, vector<string>& result) {
    // Base case: if the string has reached the required length, add it to the result
    if (current.length() == k) {
        result.push_back(current);
        return;
    }
    
    // Option 1: Add '0' to the current string
    generateBinaryStrings(k, current + '0', result);
    
    // Option 2: Add '1' to the current string, but only if the last character is not '1'
    if (current.empty() || current.back() != '1') { //REVIEW .back
        generateBinaryStrings(k, current + '1', result);
    }
}

vector<string> generateAllBinaryStrings(int k) {
    vector<string> result;
    generateBinaryStrings(k, "", result);
    return result;
}

int main() {
    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    vector<string> result = generateAllBinaryStrings(k);
    
    // Print the result
    cout << "Binary strings of length " << k << " without consecutive 1's:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
