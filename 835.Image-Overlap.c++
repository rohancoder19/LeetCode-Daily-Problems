//C++

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();

        // Collect coordinates of all 1s in img1 and img2
        std::vector<std::pair<int, int>> ones1;
        std::vector<std::pair<int, int>> ones2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        // Translation vector offsets range from -(n - 1) to (n - 1).
        // Using a 2D count array of size 2*n x 2*n with offset n.
        int count[65][65] = {0};
        int max_overlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r1 - r2 + n;
                int dc = c1 - c2 + n;

                count[dr][dc]++;
                max_overlap = std::max(max_overlap, count[dr][dc]);
            }
        }

        return max_overlap;
    }
};