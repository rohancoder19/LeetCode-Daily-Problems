//C++

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] = maximum number of strings that can be formed with i zeros and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // Traverse backwards to avoid using the same string multiple times
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
