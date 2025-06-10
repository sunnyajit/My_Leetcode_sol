class Solution {
public: // code written by sunny
    int maxDifference(string s) {
        vector<int> freq(26, 0); 
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX; 
        for (int f : freq) {
            if (f == 0) continue;
            if (f % 2 == 1) {
                maxOdd = max(maxOdd, f);
            } else {
                minEven = min(minEven, f);
            }
        }

        return maxOdd - minEven;
    }
};
