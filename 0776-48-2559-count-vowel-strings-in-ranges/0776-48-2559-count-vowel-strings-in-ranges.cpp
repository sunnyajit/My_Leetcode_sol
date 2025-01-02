class Solution {
public: // code written by sunny
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0); 
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }; 
        for (int i = 0; i < n; ++i) {
            bool startsWithVowel = isVowel(words[i].front());
            bool endsWithVowel = isVowel(words[i].back());
            prefixSum[i + 1] = prefixSum[i] + (startsWithVowel && endsWithVowel);
        } 
        vector<int> result;
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            result.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return result;
    }
};
