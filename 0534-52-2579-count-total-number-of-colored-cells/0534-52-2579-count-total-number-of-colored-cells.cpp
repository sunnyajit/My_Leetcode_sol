class Solution {
public: // code written by sunny
    long long coloredCells(int n) {
        return 1LL + 2LL * (n - 1) * n;
    }
};