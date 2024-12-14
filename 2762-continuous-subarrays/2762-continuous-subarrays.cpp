class Solution {
public: // code written by sunny
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        long long result = 0;
        deque<int> minDeque, maxDeque; 
        for (int right = 0; right < nums.size(); ++right) {
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right); 
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right); 
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                left++; 
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
            } 
            result += (right - left + 1);
        }
        return result;
    }
};
