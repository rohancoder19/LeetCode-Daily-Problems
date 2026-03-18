//Python

class Solution(object):
    def countSubmatrices(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        count = 0
        
   
        pref = [[0] * cols for _ in range(rows)]
        
        for r in range(rows):
            for c in range(cols):
               
                current_val = grid[r][c]
                above = pref[r-1][c] if r > 0 else 0
                left = pref[r][c-1] if c > 0 else 0
                overlap = pref[r-1][c-1] if (r > 0 and c > 0) else 0
                
                pref[r][c] = current_val + above + left - overlap
                
              
                if pref[r][c] <= k:
                    count += 1
                else:
                    
                    break
                    
        return count