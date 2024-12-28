class Solution {
public: // code written by sunny
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        vector<int> left(n, 0), right(n, n - k);
        for (int i = k, max_sum = sum[k] - sum[0]; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > max_sum) {
                max_sum = sum[i + 1] - sum[i + 1 - k];
                left[i] = i + 1 - k;
            } else {
                left[i] = left[i - 1];
            }
        }
        
        for (int i = n - k - 1, max_sum = sum[n] - sum[n - k]; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= max_sum) {
                max_sum = sum[i + k] - sum[i];
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        
        vector<int> result(3, -1);
        int max_sum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int total = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (total > max_sum) {
                max_sum = total;
                result = {l, i, r};
            }
        }
        
        return result;
    }
};
