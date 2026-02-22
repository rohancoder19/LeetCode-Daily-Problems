//C++

class Solution {
public:
    int binaryGap(int n) {
        std::vector<int> indices;
        
        // Find all indices where the bit is set to 1
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) {
                indices.push_back(i);
            }
        }

        // If fewer than two 1s exist, the gap is 0
        if (indices.size() < 2) {
            return 0;
        }

        int maxGap = 0;
        // Calculate the maximum difference between consecutive indices
        for (size_t i = 0; i < indices.size() - 1; ++i) {
            maxGap = std::max(maxGap, indices[i + 1] - indices[i]);
        }

        return maxGap;
    }
};