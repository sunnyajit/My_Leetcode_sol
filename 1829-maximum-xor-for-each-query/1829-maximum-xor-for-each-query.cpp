class Solution {
public: // code written by sunny
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int max_k = (1 << maximumBit) - 1;  
        int cumulativeXor = 0;
        for (int num : nums) {
            cumulativeXor ^= num;
        }
        vector<int> answer;
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer.push_back(cumulativeXor ^ max_k);
            cumulativeXor ^= nums[i];
        }
        return answer;
    }
};