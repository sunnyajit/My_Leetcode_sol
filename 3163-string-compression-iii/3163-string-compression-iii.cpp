class Solution {
public: // code written by sunny
    string compressedString(string word) {
        string comp;
        int i = 0;
        int n = word.length();
        while (i < n) {
            char currentChar = word[i];
            int count = 0;
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + currentChar;
        }
        return comp;
    }
};