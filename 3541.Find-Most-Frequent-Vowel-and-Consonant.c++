C++

class Solution {
public:
    int maxFreqSum(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(26, 0);
        int maxi_vowel = 0, maxi_consonant = 0;
        for(char ch : s){
            freq[ch-'a']++;
            bool is_vowel = false;
            for(char vowel : vowels){
                if(vowel == ch){
                    is_vowel = true;
                    break;
                }
            }
            if(is_vowel){
                maxi_vowel = max(maxi_vowel, freq[ch-'a']);
            }else{
                maxi_consonant = max(maxi_consonant, freq[ch-'a']);
            }
        }
        return maxi_vowel + maxi_consonant;
    }
};