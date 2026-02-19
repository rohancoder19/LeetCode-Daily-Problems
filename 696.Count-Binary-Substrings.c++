//C++

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        int prevGroupSize = 0;
        int currGroupSize = 1;
        int totalSubstrings = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
               
                currGroupSize++;
            } else {
                
                totalSubstrings += min(prevGroupSize, currGroupSize);
                
                
                prevGroupSize = currGroupSize;
                currGroupSize = 1;
            }
        }

        
        totalSubstrings += min(prevGroupSize, currGroupSize);

        return totalSubstrings;
    }
};