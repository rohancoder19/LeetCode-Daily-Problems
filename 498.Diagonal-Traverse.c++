498.Diagonal-Traverse:

//C++

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        // Traverse all possible diagonals
        for (int d = 0; d < m + n - 1; d++) {
            // temporary diagonal vector
            vector<int> diagonal;
            
            // figure out row and column to start from
            int r = (d < n) ? 0 : d - n + 1;
            int c = (d < n) ? d : n - 1;
            
            // Collect diagonal elements
            while (r < m && c >= 0) {
                diagonal.push_back(mat[r][c]);
                r++;
                c--;
            }
            
            // Reverse every alternate diagonal
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }
            
            result.insert(result.end(), diagonal.begin(), diagonal.end());
        }
        
        return result;
    }
};
