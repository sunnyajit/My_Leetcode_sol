 class Solution {
public: // code written by sunny
    int minGroups(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      priority_queue<int,  vector<int>,  greater<int>> minHeap;
        for (const auto& interval : intervals) {
             if (!minHeap.empty() && minHeap.top() < interval[0]) {
                minHeap.pop();  
            }
            minHeap.push(interval[1]);
        }
        return minHeap.size();
    }
};