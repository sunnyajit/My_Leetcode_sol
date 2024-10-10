class Solution {
public: // code written by sunny
    bool canArrange(vector<int>& arr, int k) {
         unordered_map<int, int> remainderCount;
    for (int num : arr) {
        int remainder = (num % k + k) % k;  
        remainderCount[remainder]++;
    }
    for (int r = 0; r < k; ++r) {
        if (remainderCount[r] > 0) {
            if (r == 0) {
                if (remainderCount[r] % 2 != 0) return false;
            } else {
                int complement = k - r;
                if (remainderCount.find(complement) == remainderCount.end() || 
                    remainderCount[complement] != remainderCount[r]) {
                    return false;
                }
            }
        }
    }
    
    return true;
    }
};