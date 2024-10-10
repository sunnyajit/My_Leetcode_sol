class MyCalendarTwo {
public:
// code written by sunny
  vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        for (auto &overlap : overlaps) {   
            if (max(start, overlap.first) < min(end, overlap.second)) {
                return false;  
            }
        }
        for (auto &event : events) {
            int overlap_start = max(start, event.first);
            int overlap_end = min(end, event.second);
            if (overlap_start < overlap_end) {
                overlaps.push_back({overlap_start, overlap_end});
            }
        }
        events.push_back({start, end});
        return true;
    }
};