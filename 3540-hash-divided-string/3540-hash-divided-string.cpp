 class Solution {
public: // code written by sunny
    string stringHash(string s, int k) {
     int n = s.length();
     string result;
    for (int i = 0; i < n; i += k) {
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            char c = s[i + j];
            sum += c - 'a';   
        }
        int hashedChar = sum % 26;
        char resultChar = 'a' + hashedChar;
        result += resultChar;
    }
    return result;
    }
};