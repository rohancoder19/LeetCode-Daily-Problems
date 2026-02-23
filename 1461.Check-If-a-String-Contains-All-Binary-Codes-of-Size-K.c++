//C++

class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        
        if (s.length() < k) {
            return false;
        }

        std::unordered_set<std::string> seenCodes;
        int totalRequired = 1 << k; 

        
        for (int i = 0; i <= (int)s.length() - k; ++i) {
            seenCodes.insert(s.substr(i, k));
            
            
            if (seenCodes.size() == totalRequired) {
                return true;
            }
        }

        return seenCodes.size() == totalRequired;
    }
};