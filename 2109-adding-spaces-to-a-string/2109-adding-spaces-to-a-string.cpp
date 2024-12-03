class Solution {
public: // code written by sunny
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.length();
        int m = spaces.size();
        int spaceIndex = 0;  
        for (int i = 0; i < n; ++i) {
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                result += ' ';
                ++spaceIndex; 
            }
            result += s[i];  
        }
        
        return result;
    }
};
