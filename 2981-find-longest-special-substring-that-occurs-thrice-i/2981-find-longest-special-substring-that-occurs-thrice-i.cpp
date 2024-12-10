 
class Solution {
public: // code written by sunny
    int maximumLength( string s) {
        int n = s.length(); 
        for (int len = n; len >= 1; len--) {
            unordered_map< string, int> freq;
              
            for (int i = 0; i <= n - len; i++) {
                string substring = s.substr(i, len);
                 
                if (isSpecial(substring)) {
                    freq[substring]++;
                }
            } 
            for (const auto& pair : freq) {
                if (pair.second >= 3) {
                    return len; 
                }
            }
        } 
        return -1;
    }
    
private:
    bool isSpecial(const string& str) {
        char c = str[0];
        for (char ch : str) {
            if (ch != c) return false;
        }
        return true;
    }
};
