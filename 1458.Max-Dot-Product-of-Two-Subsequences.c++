//C++

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int prod = nums1[i] * nums2[j];

                if (i > 0 && j > 0)
                    dp[i][j] = max(dp[i][j], prod + max(0, dp[i - 1][j - 1]));
                else
                    dp[i][j] = max(dp[i][j], prod);

                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};
