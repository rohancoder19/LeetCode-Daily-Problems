//C++

#include <unordered_set>

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
       
        std::unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        
        for (int i = L; i <= R; ++i) {
          
            if (primes.count(__builtin_popcount(i))) {
                count++;
            }
        }
        
        return count;
    }
};