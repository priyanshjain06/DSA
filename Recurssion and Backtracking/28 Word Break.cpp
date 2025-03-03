#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Trace(const string& run, int target, string expression, long evaluated, long residual, int index, vector<string>& result) {
    if (index == run.length()) {
        if (evaluated == target) {
            result.push_back(expression);
        }
        return;
    }

    for (int i = index; i < run.length(); ++i) {
        if (i != index && run[index] == '0') break; // Skip numbers with leading zeros

        // Convert substring to number manually for beginners
        long currentNum = 0;
        for (int j = index; j <= i; ++j) {
            currentNum = currentNum * 10 + (run[j] - '0'); // Building number manually
        }

        if (index == 0) {
            Trace(run, target, expression + to_string(currentNum), currentNum, currentNum, i + 1, result);
        } else {
            Trace(run, target, expression + "+" + to_string(currentNum), evaluated + currentNum, currentNum, i + 1, result);
            Trace(run, target, expression + "-" + to_string(currentNum), evaluated - currentNum, -currentNum, i + 1, result);
            Trace(run, target, expression + "*" + to_string(currentNum), evaluated - residual + residual * currentNum, residual * currentNum, i + 1, result);
        }
    }
}

vector<string> Composite(string run, int target) {
    vector<string> result;
    Trace(run, target, "", 0, 0, 0, result);
    return result;
}

int main() {
    string run = "123";
    int target = 6;
    vector<string> result = Composite(run, target);

    cout << "Input: run = \"" << run << "\", target = " << target << endl;
    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
