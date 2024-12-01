class Solution {
public: // code  written by sunny
    int smallestNumber(int n) {
        while ((n & (n + 1)) != 0) {
            n++;
        }
        return n;
    }
};
