 

class Solution {
public:
     // code written by sunny
    bool isFeasible(vector<int>& nums, int maxSize, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            if (num > maxSize) {
                operations += (num - 1) / maxSize; 
            }
            if (operations > maxOperations) {
                return false;  
            }
        }
        return true;
    } 
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1; 
        int right = *max_element(nums.begin(), nums.end());  
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isFeasible(nums, mid, maxOperations)) {
                result = mid;  
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};
