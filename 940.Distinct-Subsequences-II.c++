//C++

#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        const int MOD = 1e9 + 7;
        
        // ends_with[i] stores the count of distinct non-empty subsequences ending with ('a' + i)
        std::vector<long long> ends_with(26, 0);

        for (char ch : s) {
            int idx = ch - 'a';
            
            // Calculate 1 + sum of all distinct subsequences so far
            long long sum_all = 0;
            for (int i = 0; i < 26; ++i) {
                sum_all = (sum_all + ends_with[i]) % MOD;
            }
            
            // New distinct subsequences ending with current char
            ends_with[idx] = (sum_all + 1) % MOD;
        }

        // Sum up distinct subsequences ending with each of the 26 characters
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + ends_with[i]) % MOD;
        }

        return total;
    }
};