//C++

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int W = A[0].size();
        vector<int> dp(W, 1);

        for (int i = W - 2; i >= 0; i--) {
            for (int j = i + 1; j < W; j++) {
                bool ok = true;

                // Check all rows
                for (const string& row : A) {
                    if (row[i] > row[j]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int kept = 0;
        for (int x : dp)
            kept = max(kept, x);

        return W - kept;
    }
};
