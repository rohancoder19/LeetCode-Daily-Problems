//C++

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();

        bool mp[26];
        for(char &ch : brokenLetters) {
            mp[ch-'a'] = true;
        }

        int result        = 0;
        bool foundBroken  = false;
        for(char &ch : text) {
            if(ch == ' ') {
                if(!foundBroken) {
                    result++;
                }
                foundBroken = false;
            } else if (mp[ch - 'a']) {
                foundBroken = true; //found
            }
        }
        if(foundBroken == 0)
            result++;

        return result;
    }
};