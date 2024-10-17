 class Solution {
public: // code written by sunny
    long long validSubstringCount(string word1, string word2) {
         int n = word1.size(); 
        int m = word2.size(); 
        if (m > n) return 0; 
       unordered_map<char, int> count2, count1; 
        for (char c : word2) { 
            count2[c]++; 
        } 
        long long result = 0; 
        int required = count2.size(); 
        int formed = 0;  
        int left = 0;  
        for (int right = 0; right < n; ++right) { 
            char c = word1[right]; 
            count1[c]++; 
            if (count2.count(c) && count1[c] == count2[c]) { 
                formed++; 
            } 
            while (formed == required) { 
                result += (n - right); 
                char leftChar = word1[left]; 
                count1[leftChar]--; 
                if (count2.count(leftChar) && count1[leftChar] < count2[leftChar]) { 
                    formed--; 
                } 
                left++; 
            } 
        } 
        return result; 
    }
};