// #include <vector>
// #include <algorithm>

class Solution {
public:// code written by sunny
    int maximumCount(vector<int>& nums) {
        int first_non_negative_index = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(); 
        int negative_count = first_non_negative_index;
        int positive_count = nums.size() - first_non_negative_index - std::count(nums.begin(), nums.end(), 0); 
        return max(negative_count, positive_count);
    }
};
