//C++

class Solution {
public:
    bool validCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<vector<string>> buckets(4);

        int n = code.size();
        for (int i = 0; i < n; i++) {

            if (!isActive[i]) continue;
            if (!validCode(code[i])) continue;
            if (priority.find(businessLine[i]) == priority.end()) continue;

            buckets[priority[businessLine[i]]].push_back(code[i]);
        }

        vector<string> result;
        for (int i = 0; i < 4; i++) {
            sort(buckets[i].begin(), buckets[i].end());
            for (auto &c : buckets[i]) {
                result.push_back(c);
            }
        }

        return result;
    }
};
