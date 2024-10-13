 
class Solution {
public: // code written by sunny
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);  
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> minHeap(cmp);

        int currentMax = numeric_limits<int>::min();  
        int rangeStart = 0, rangeEnd = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i][0], i, 0);
            currentMax = max(currentMax, nums[i][0]);
        }
        while (minHeap.size() == nums.size()) {
            auto [currentMin, listIdx, elementIdx] = minHeap.top();
            minHeap.pop();
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            } 
            if (elementIdx + 1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][elementIdx + 1];
                minHeap.emplace(nextElement, listIdx, elementIdx + 1);
                currentMax = max(currentMax, nextElement);
            }
        }

        return {rangeStart, rangeEnd};
    }
};
