 

class Solution {
public: // code written by sunny
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](const pair<int, int>& a) {
            int pass = a.first, total = a.second;
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            maxHeap.push({gain({pass, total}), {pass, total}});
        } 
        while (extraStudents--) {
            auto top = maxHeap.top(); maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second; 
            pass += 1;
            total += 1; 
            maxHeap.push({gain({pass, total}), {pass, total}});
        } 
        double averagePassRatio = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top(); maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second;
            averagePassRatio += (double)pass / total;
        }
        
        return averagePassRatio / classes.size();
    }
};
