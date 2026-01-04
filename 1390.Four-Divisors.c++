//C++

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0;
            int sum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int e = x / d;

                    if (d == e) {
                        cnt++;
                        sum += d;
                    } else {
                        cnt += 2;
                        sum += d + e;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4)
                ans += sum;
        }

        return ans;
    }
};
