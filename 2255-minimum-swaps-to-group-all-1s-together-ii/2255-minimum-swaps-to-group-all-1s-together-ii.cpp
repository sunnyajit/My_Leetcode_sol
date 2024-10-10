 class Solution {
public: // code written by sunny..
    int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int onesCount = accumulate(nums.begin(), nums.end(), 0);   
    if (onesCount == 0) return 0;   
    if (onesCount == n) return 0;   
    vector<int> extended(nums.begin(), nums.end());
    extended.insert(extended.end(), nums.begin(), nums.end());   
    int currentCount = 0;
    for (int i = 0; i < onesCount; ++i) {
        if (extended[i] == 1) currentCount++;
    }
    int maxOnesInWindow = currentCount;
    for (int i = onesCount; i < extended.size(); ++i) {
        if (extended[i] == 1) currentCount++;
        if (extended[i - onesCount] == 1) currentCount--;
        maxOnesInWindow = max(maxOnesInWindow, currentCount);
    }

    return onesCount - maxOnesInWindow;
    }
};