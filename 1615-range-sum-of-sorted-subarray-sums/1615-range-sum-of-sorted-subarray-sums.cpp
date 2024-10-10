const int MOD = 1e9 + 7;
class Solution {
public: // code written by sunny..
    int rangeSum(vector<int>& nums, int n, int left, int right) {
   n = nums.size();
    vector<long long> subarraySums;
    for (int start = 0; start < n; ++start) {
        long long currentSum = 0;
        for (int end = start; end < n; ++end) {
            currentSum += nums[end];
            subarraySums.push_back(currentSum);
        }
    }
    sort(subarraySums.begin(), subarraySums.end());
    long long result = 0;
    for (int i = left - 1; i < right; ++i) {
        result = (result + subarraySums[i]) % MOD;
    }
    return result;
    }
};