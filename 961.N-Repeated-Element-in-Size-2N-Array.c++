//C++

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> count;

        for (int x : A)
            count[x]++;

        for (auto &p : count) {
            if (p.second > 1)
                return p.first;
        }

        return -1; 
    }
};
