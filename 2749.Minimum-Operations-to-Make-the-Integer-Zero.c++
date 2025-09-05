
//C++

class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        long long k = 1;
        while(true){
            // num2 handling
            long long res = num1*1LL - k*num2*1LL;
            if(res < k){
                return -1;
            }
            // power of 2's handling
            long long count_of_bits = 0;
            for(long long i=0; i<60; i++){
                if(res & (1LL << i)){
                    count_of_bits++;
                }
            }
            if(count_of_bits <= k){
                return k;
            }
            k++;
        }
        return -1;
    }
};