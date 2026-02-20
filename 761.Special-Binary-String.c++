//C++

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> components;

        
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '1') count++;
            else count--;

            if (count == 0) {
                
                components.push_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
                i = j + 1;
            }
        }

       
        sort(components.begin(), components.end(), greater<string>());

        
        string res = "";
        for (const string& comp : components) {
            res += comp;
        }
        
        return res;
    }
};