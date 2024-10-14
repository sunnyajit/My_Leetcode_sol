class Solution {
public:  // code written by sunny
    long long maxKelements(vector<int>& nums, int k) {
          priority_queue<int> maxHeap;
        for (int num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;
        for (int i = 0; i < k; ++i) {
            int maxNum = maxHeap.top();
            maxHeap.pop();
            score += maxNum;
            int newNum = (maxNum + 2) / 3; 
            maxHeap.push(newNum);
        }
        return score;
    }
};