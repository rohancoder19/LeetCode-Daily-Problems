//C++

class Solution {
public:
    char findKthBit(int n, int k) {
        string sequence = "0";

      
    
        for (int i = 1; i < n && k > sequence.length(); ++i) {
            sequence += '1';

         
            string temp = sequence;
            for (int j = temp.length() - 2; j >= 0; --j) {
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                sequence += invertedBit;
            }
        }

 
        return sequence[k - 1];
    }
};