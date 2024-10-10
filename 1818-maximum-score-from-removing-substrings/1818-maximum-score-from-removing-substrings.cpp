 class Solution {
public: // code written by sunnny..
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            reverse(s.begin(), s.end());
            return maximumGain(s, y, x);
        }
        int ans = 0;
        stack<char> t1;
        stack<char> t2;
        for (char c : s) {
            if (c != 'b')
                t1.push(c);
            else {
                if (!t1.empty() && t1.top() == 'a') {
                    t1.pop();
                    ans += x;
                } else
                    t1.push(c);
            }
        }
        while (!t1.empty()) {
            char c = t1.top();
            t1.pop();
            if (c != 'b')
                t2.push(c);
            else {
                if (!t2.empty() && t2.top() == 'a') {
                    t2.pop();
                    ans += y;
                } else
                    t2.push(c);
            }
        }
        return ans;
    }
};