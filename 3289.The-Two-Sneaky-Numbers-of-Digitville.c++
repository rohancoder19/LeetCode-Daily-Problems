//C++

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        int y = 0;
        for (int x : nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & (-y);
        int x1 = 0, x2 = 0;
        for (int x : nums) {
            if (x & lowBit) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i & lowBit) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return {x1, x2};
    }
};