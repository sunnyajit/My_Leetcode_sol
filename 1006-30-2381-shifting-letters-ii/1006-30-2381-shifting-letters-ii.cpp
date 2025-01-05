class Solution {
public: // code written by sunny
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            delta[start] += (direction == 1) ? 1 : -1;
            delta[end + 1] += (direction == 1) ? -1 : 1;
        }

        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += delta[i];
            int newChar = ((s[i] - 'a') + netShift) % 26;
            if (newChar < 0) newChar += 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
