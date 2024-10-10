 class Solution {
public: // code written by sunny
      int countPairsWithDistanceLessEqual(const vector<int>& nums, int distance) {
        int count = 0;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && nums[j] - nums[i] <= distance) {
                ++j;
            }
            count += (j - i - 1);  
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.back() - nums.front();
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countPairsWithDistanceLessEqual(nums, mid) < k) {
                left = mid + 1;
            } else {
                result = mid;
                right = mid - 1;
            }
        }

        return result;
        
    }
};