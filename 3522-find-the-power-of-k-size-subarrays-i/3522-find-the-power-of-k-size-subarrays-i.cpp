 class Solution {
public: // code written by sunny
    vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> results(n - k + 1);
    for (int i = 0; i <= n - k; ++i) {
        vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
        int minElement = *min_element(subarray.begin(), subarray.end());
        int maxElement = *max_element(subarray.begin(), subarray.end());
        if (maxElement - minElement == k - 1) {
            bool isConsecutive = true;
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
            }
            results[i] = isConsecutive ? maxElement : -1;
        } else {
            results[i] = -1;
        }
    }
    return results;
    }
};