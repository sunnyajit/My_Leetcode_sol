class Solution {
public: // code written by sunny
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int lastIndex = 0; 
        int l = nums[0];
        
    
        for (int i = 1; i < n; i++) {
            if (nums[i] > l) { 
                ans += l * 1ll * (i - lastIndex);
                l = nums[i];
                lastIndex = i; 
            }
        }
        ans += l * 1ll * (n - 1 - lastIndex);
        return ans;
    }
    
};