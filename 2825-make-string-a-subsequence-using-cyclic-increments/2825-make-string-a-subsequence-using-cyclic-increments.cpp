class Solution {
public: // code written by sunny
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n1 = str1.size(), n2 = str2.size();
        while (i < n1 && j < n2) {
            char c1 = str1[i];
            char c2 = str2[j];
            if (c1 == c2 || (c1 == 'z' && c2 == 'a') || (c1 + 1 == c2)) {
                j++;   
            }
            i++;  
        }

        return j == n2;
    }
};
