class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long value = 0;
        long long base = 1;
        int n = s.size();

        // First, include as many bits from the right as possible without exceeding k
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (base <= k && value + base <= k) {
                    value += base;
                    count++;
                }
            } else {
                // '0' can always be added — as long as it doesn’t break k
                count++;
            }

            base *= 2;
            if (base > k) break; // avoid unnecessary large shifts
        }

        // Now count remaining zeros (left side) that we can safely add (they don't increase value)
        for (int i = n - count - 1; i >= 0; --i) {
            if (s[i] == '0') count++;
        }

        return count;
    }
};
