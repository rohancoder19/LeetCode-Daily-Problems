//C++

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ptr = 0;

        for (int i = 0; i < nums.size(); i++) {
            ptr = ptr ^ nums[i];
        }

        return ptr;
    }
};