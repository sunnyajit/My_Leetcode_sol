 class Solution {
public: // code written by sunny
    bool primeFlags[1000];
    void sieve() {  
        fill(primeFlags, primeFlags + 1000, true);
        primeFlags[0] = false;  
        primeFlags[1] = false;  
        for (int i = 2; i * i < 1000; i++) {
            if (primeFlags[i] == true) {
                for (int j = i * i; j < 1000; j += i) {
                    primeFlags[j] = false;  
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        sieve(); 
        for (int i = n - 2; i >= 0; i--) {  
            if (nums[i] < nums[i + 1]) {
                continue; 
            }
            for (int primeCandidate = 2; primeCandidate < nums[i]; primeCandidate++) {   
                if (!primeFlags[primeCandidate]) {
                    continue; 
                }

                if (nums[i] - primeCandidate < nums[i + 1]) {
                    nums[i] -= primeCandidate;
                    break;
                }
            }
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
