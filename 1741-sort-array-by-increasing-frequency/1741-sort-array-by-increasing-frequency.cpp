class Solution {
public: // code written by sunny...
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;    
            } else {
                return a.second < b.second; 
            }
        };
     
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
     
        sort(freqVec.begin(), freqVec.end(), comp);
         
        vector<int> result;
        for (auto& pair : freqVec) {
            int num = pair.first;
            int count = pair.second;
            for (int i = 0; i < count; ++i) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};