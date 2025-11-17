//C++

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;  // stores the index of the last seen '1'

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                // If this is not the first 1, check distance
                if (last != -1 && i - last - 1 < k)
                    return false;

                last = i;  // update last position of 1
            }
        }

        return true;
    }
};
