class Solution {
public: // code written by sunny
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        } 
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);  
            if (i == end) { 
                result.push_back(end - start + 1);  
                start = i + 1; 
            }
        }

        return result;
    }
};
