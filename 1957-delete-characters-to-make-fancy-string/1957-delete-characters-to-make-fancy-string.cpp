class Solution {
public: //  code written by sunny
    string makeFancyString(string s) {
         string result;   
        int count = 0;        
        for (int i = 0; i < s.length(); ++i) {
            if (!result.empty() && result.back() == s[i]) {
                count++;   
            } else {
                count = 1;  
            }
            if (count < 3) {
                result += s[i];
            }
        }

        return result;  
    }
};