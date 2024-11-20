class Solution {
public: // code written by sunny
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> total(3, 0); 
        for (char c : s) {
            total[c - 'a']++;
        }
        if (total[0] < k || total[1] < k || total[2] < k) {
            return -1;
        }
        int maxMiddleLength = 0;
        vector<int> current(3, 0); 
        int left = 0;
        for (int right = 0; right < n; right++) {
            current[s[right] - 'a']++;
            while (current[0] > total[0] - k || current[1] > total[1] - k || current[2] > total[2] - k) {
                current[s[left] - 'a']--;
                left++;
            }
            maxMiddleLength = max(maxMiddleLength, right - left + 1);
        }
        return n - maxMiddleLength;
    }
};
