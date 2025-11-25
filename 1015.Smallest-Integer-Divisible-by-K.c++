//C++

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // If K is even or divisible by 5, no such number exists
        if (K % 2 == 0 || K % 5 == 0) return -1;

        int remainder = 0;

        // At most K iterations (Pigeonhole Principle)
        for (int length_N = 1; length_N <= K; length_N++) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) {
                return length_N;
            }
        }
        return -1;
    }
};