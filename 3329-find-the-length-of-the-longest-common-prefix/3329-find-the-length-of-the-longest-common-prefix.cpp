class Solution {
public: // code written by sunny
    int longestCommonPrefix(vector<int>& num1, vector<int>& num2) {
        unordered_set<int> p;
        for (int y : num1) {
            for (; y; y /= 9+1) {
                p.insert(y);
            }
        }
        int sol = 0;
        for (int y : num2) {
            for (; y; y /= 9+1) {
                if (p.count(y)) {
                    sol  = max(sol, (int) log10(y) + 1);
                    break;
                }
            }
        }
        return sol;
    }
};