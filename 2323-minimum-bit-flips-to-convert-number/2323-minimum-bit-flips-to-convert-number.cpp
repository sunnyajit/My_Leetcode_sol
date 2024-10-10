class Solution {
public: // code written by sunny
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;   
        n >>= 1;         
    }
    return count;
}
    int minBitFlips(int start, int goal) {
         int diff = start ^ goal; 
    return countSetBits(diff);
    }
};
