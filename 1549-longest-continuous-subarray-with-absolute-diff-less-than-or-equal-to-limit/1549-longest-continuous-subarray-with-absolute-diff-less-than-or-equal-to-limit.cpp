class Solution {
public: // code written by sunny
    int longestSubarray(vector<int>& nums, int limit) {
    int left = 0, right = 0;
    int maxLength = 0;
    deque<int> maxDeque, minDeque;

    while (right < nums.size()) {
        
        while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(nums[right]);
        while (!minDeque.empty() && nums[right] < minDeque.back()) {
            minDeque.pop_back();
        }
        minDeque.push_back(nums[right]);
        while (!maxDeque.empty() && !minDeque.empty() && (maxDeque.front() - minDeque.front() > limit)) {
            if (nums[left] == maxDeque.front()) {
                maxDeque.pop_front();
            }
            if (nums[left] == minDeque.front()) {
                minDeque.pop_front();
            }
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}

int main() {
    vector<int> nums1 = {8, 2, 4, 7};
    int limit1 = 4;
    cout << "Example 1 Output: " << longestSubarray(nums1, limit1) << endl; 

    vector<int> nums2 = {10, 1, 2, 4, 7, 2};
    int limit2 = 5;
    cout << "Example 2 Output: " << longestSubarray(nums2, limit2) << endl; 

    vector<int> nums3 = {4, 2, 2, 2, 4, 4, 2, 2};
    int limit3 = 0;
    cout << "Example 3 Output: " << longestSubarray(nums3, limit3) << endl; // Output: 3

    return 0;
}

};