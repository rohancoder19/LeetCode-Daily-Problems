//C++

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
 
        // The first element is always the cost of the first subarray
        int firstCost = nums[0];
 
        // We need to find the two smallest elements in the remaining part of the array
        int min1 = INT_MAX;
        int min2 = INT_MAX;
 
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
 
        return firstCost + min1 + min2;
    }
};