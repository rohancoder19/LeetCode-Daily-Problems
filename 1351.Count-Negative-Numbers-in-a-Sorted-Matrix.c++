//C++

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m - 1;
        int col = 0;
        int count = 0;
        
        // Start from bottom-left corner
        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                // All elements to the right are also negative
                count += (n - col);
                row--; // move up
            } else {
                col++; // move right
            }
        }
        
        return count;
    }
};
