class Solution {
public: // code written by sunny
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitMask = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((bitMask & nums[right]) != 0) {  
                bitMask ^= nums[left];  
                left++;
            }
            bitMask |= nums[right]; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
