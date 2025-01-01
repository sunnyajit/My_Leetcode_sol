class Solution {
public: // code written by sunny
    int maxScore(string s) {
        int totalOnes = count(s.begin(), s.end(), '1');
        int leftZeros = 0, rightOnes = totalOnes;
        int maxScore = 0;

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};
