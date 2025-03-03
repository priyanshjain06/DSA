#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool backtrack(int i, int j, vector<vector<char>>& board, string& word, int index) {
        // Base case: If we've matched all characters
        if (index == word.size()) return true;

        // Check bounds and if the character matches
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the current cell as visited by replacing the character
        char temp = board[i][j];
        board[i][j] = '#';  // Temporary marker to avoid revisiting

        // Explore all 4 directions (up, down, left, right)
        bool found = backtrack(i + 1, j, board, word, index + 1) ||
                     backtrack(i - 1, j, board, word, index + 1) ||
                     backtrack(i, j + 1, board, word, index + 1) ||
                     backtrack(i, j - 1, board, word, index + 1);

        // Restore the cell's original character
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;

        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start the search from each cell
                if (board[i][j] == word[0] && backtrack(i, j, board, word, 0)) {
                    return true;
                }
            }
        }

        return false; 
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    bool result = sol.exist(board, word);

    cout << (result ? "true" : "false") << endl;
    return 0;
}
