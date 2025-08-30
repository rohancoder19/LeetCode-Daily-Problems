3021.Alice_Bob_Playing_Flower_Game:

//C++

class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);
    }
};