 class Solution {
public: // code written by sunny
    int findTheLongestSubstring(string s) {
          unordered_map<char, int> vowel_map = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    unordered_map<int, int> mask_index;
    int mask = 0;
    mask_index[mask] = -1;  
    
    int max_len = 0;
    
    for (int i = 0; i < s.length(); ++i) {
      
        if (vowel_map.count(s[i])) {
            mask ^= (1 << vowel_map[s[i]]);
        }
        if (mask_index.count(mask)) {
            max_len = max(max_len, i - mask_index[mask]);
        } else {
           
            mask_index[mask] = i;
        }
    }
    
    return max_len;
    }
};