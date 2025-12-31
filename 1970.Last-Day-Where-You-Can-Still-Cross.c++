//C++

class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        // Flood first "day" cells
        for (int i = 0; i < day; i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        
        // Start from top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == row - 1) return true;
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
    
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r;
        col = c;
        
        int low = 1, high = cells.size(), ans = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (canCross(mid, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
