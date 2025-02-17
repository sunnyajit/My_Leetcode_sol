class Solution {
public: // code written by sunny
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                freq[ch]--;
                count += 1 + backtrack(freq);
                freq[ch]++;
            }
        }
        return count;
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;
        
        return backtrack(freq);
    }
};
