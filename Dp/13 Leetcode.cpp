class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(matrix[0]); // REVIEW  initialize with first row
        vector<int> cur(m, 0);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j] + (j > 0 ? prev[j - 1] : 1e9); // SECTION -  +1ep9 not -1e9
                int rightDiagonal = matrix[i][j] + (j + 1 < m ? prev[j + 1] : 1e9);

                cur[j] = min({up, leftDiagonal, rightDiagonal});
            }
            prev = cur;
        }

        return *min_element(prev.begin(), prev.end()); // REVIEW min element instead of max sicne we need to return asnwer in sorted way
    }
};
