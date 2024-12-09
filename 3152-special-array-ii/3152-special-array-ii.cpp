class Solution {
public: // code written by sunny
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> parityMismatch(n - 1, false);
        for (int i = 0; i < n - 1; ++i) {
            parityMismatch[i] = (nums[i] % 2 != nums[i + 1] % 2);
        } 
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + (parityMismatch[i - 1] ? 1 : 0);
        } 
        vector<bool> result;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1]; 
            int mismatchCount = prefixSum[r] - prefixSum[l]; 
            result.push_back(mismatchCount == (r - l));
        }
        
        return result;
    }
};
