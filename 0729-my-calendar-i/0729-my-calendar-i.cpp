class MyCalendar {
public: // code written by sunny
vector<pair<int, int>> bookings;
    MyCalendar() {
    }
    bool book(int start, int end) {
         for (auto& event : bookings) {
            if (max(event.first, start) < min(event.second, end)) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};