//C++

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        
        for (auto& q : queries) {
            long long l = q[0], r = q[1], sum = 0, operation = 0;

            for (long long range = 1; range <= r; range *= 4) {
                long long sr = max(range, l);
                long long er = min((long long)r, range * 4 - 1);

                if (sr <= er) {
                    sum += (++operation) * (er - sr + 1);
                } else {
                    ++operation;
                }
            }

            result += (sum + 1) / 2;
        }
        
        return result;
    }
};