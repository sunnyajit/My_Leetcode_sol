class Solution {
public: // code written by sunny
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long left_sum = 0;
        int count = 0; 
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            left_sum += nums[i];
            long long right_sum = total_sum - left_sum;

            if (left_sum >= right_sum) {
                count++;
            }
        }

        return count;
    }
};
