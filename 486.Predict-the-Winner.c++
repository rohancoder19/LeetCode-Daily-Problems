//C++

#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // Base cases: single element subarray
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Process subarrays of increasing length from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], 
                                    nums[j] - dp[i][j - 1]);
            }
        }

        // If score difference is >= 0, Player 1 wins or ties
        return dp[0][n - 1] >= 0;
    }
};