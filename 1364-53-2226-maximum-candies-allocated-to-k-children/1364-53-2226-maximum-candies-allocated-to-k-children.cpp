class Solution {
public: // code written by sunny
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long count = 0;
            for (int c : candies) {
                count += (c / mid);  
            }
            
            if (count >= k) { 
                ans = mid; 
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};
