 class Solution {
public: // code written by sunnyajit
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; 
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            int remainder = prefixSum % k;
            
            // Adjust for negative remainders
            if (remainder < 0) {
                remainder += k;
            }
            
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            
            remainderCount[remainder]++;
        }
        
        return count;
    
    }
};