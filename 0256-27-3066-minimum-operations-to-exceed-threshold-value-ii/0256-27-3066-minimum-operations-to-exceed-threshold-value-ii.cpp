class Solution {
public: // code written by sunny
    int minOperations( vector<int>& nums, int k) {
     priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
        }

        int operations = 0;
        
        while (minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            
            long long newElem = x * 2 + y;
            minHeap.push(newElem);
            
            operations++;
        }
        
        return operations;
    }
};
