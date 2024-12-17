class Solution {
public: // code written by sunny
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        int prevChar = -1;

        while (true) {
            bool added = false;

            for (int i = 25; i >= 0; --i) {
                if (freq[i] == 0 || i == prevChar) continue;

                int toAdd = min(freq[i], repeatLimit);
                result.append(toAdd, 'a' + i);
                freq[i] -= toAdd;
                added = true;

                if (freq[i] > 0) {
                    bool found = false;
                    for (int j = i - 1; j >= 0; --j) {
                        if (freq[j] > 0) {
                            result += ('a' + j);
                            freq[j]--;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        return result;
                    }
                }

                break;
            }

            if (!added) break;
        }

        return result;
    }
};

