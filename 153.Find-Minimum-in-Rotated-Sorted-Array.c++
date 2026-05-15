//C++

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            mid = l + (r-l)/2;
          
            if(nums[mid] > nums[r]) {
                l = mid+1;            
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
    
    int findMin(vector<int>& nums) {
        return findPivot(nums);
    }
};