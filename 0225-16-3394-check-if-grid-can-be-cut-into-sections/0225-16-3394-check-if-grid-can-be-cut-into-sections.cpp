// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:  // code written by sunny
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_intervals, y_intervals; 
        for (auto& rect : rectangles) {
            x_intervals.emplace_back(rect[0], rect[2]);  
            y_intervals.emplace_back(rect[1], rect[3]); 
        } 
        if (merge(x_intervals) > 2) return true;
        if (merge(y_intervals) > 2) return true;
        
        return false;
    }

private:
    int merge(vector<pair<int, int>>& intervals) {
        if (intervals.empty()) return 0; 
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            auto& last = merged.back();
            if (last.second > intervals[i].first) { 
                last.second = max(last.second, intervals[i].second);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged.size();
    }
};
