//C++

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

      
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);

        
        vector<pair<char,char>> pairs = {
            {'a','b'}, {'a','c'}, {'b','c'}
        };

        for(auto p : pairs) {
            unordered_map<int,int> mp;
            mp[0] = -1;

            int diff = 0;
            int start = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] != p.first && s[i] != p.second) {
                    // reset if third character appears
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                    continue;
                }

                if(s[i] == p.first) diff++;
                else diff--;

                if(mp.count(diff))
                    ans = max(ans, i - mp[diff]);
                else
                    mp[diff] = i;
            }
        }

      
        unordered_map<long long,int> mp;
        mp[0] = -1;

        int a = 0, b = 0, c = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;

            long long d1 = a - b;
            long long d2 = a - c;

            long long key = (d1 << 32) ^ (d2 & 0xffffffff);

            if(mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
};
