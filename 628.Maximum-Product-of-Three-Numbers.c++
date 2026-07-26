//C++

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        // Track 3 largest numbers
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        // Track 2 smallest numbers
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int n : nums) {
            // Update 3 maximums
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }
            
            // Update 2 minimums
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        
        // Return the maximum product of the two potential scenarios
        return std::max(max1 * max2 * max3, min1 * min2 * max1);
    }
};
