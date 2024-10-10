 class Solution {
public: // code written by sunny
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
         stack<int> indices;
        for (int i = 0; i < n; i++) {
            if (indices.empty() || nums[i] < nums[indices.top()]) {
                indices.push(i);
            }
        }
        int max_width = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (!indices.empty() && nums[j] >= nums[indices.top()]) {
                max_width =  max(max_width, j - indices.top());
                indices.pop();
            }
        }
        return max_width;
    }
};