//C++


class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                // A must be on the upper-left of B (lines allowed)
                if (!(x1 <= x2 && y1 >= y2)) continue;

                bool blocked = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    int x = points[k][0];
                    int y = points[k][1];

                    // must block if point is inside OR on border
                    if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                        blocked = true;
                        break;
                    }
                }

                if (!blocked) count++;
            }
        }

        return count;
    }
};
