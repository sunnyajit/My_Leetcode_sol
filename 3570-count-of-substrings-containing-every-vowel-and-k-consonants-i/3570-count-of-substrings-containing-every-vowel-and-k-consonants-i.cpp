 class Solution {
public: // code written by sunny
  bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countOfSubstrings(string word, int k) {
         int n = word.length();
        int result = 0;
        for (int start = 0; start < n; ++start) {
            unordered_set<char> vowelSet;   
            int consonants = 0;  
            for (int end = start; end < n; ++end) {
                char currentChar = word[end];
                
                if (isVowel(currentChar)) {
                    vowelSet.insert(currentChar); 
                } else {
                    consonants++;  
                }
                if (vowelSet.size() == 5 && consonants == k) {
                    result++;   
                }
            }
        }
        
        return result;
    }
};