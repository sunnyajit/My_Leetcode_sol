 class Solution {
public: // code written by sunny
    int minLength(string s) {
        stack<char> stk;
        for (char ch : s) {
            stk.push(ch);
            if (stk.size() >= 2) {
                char second = stk.top(); stk.pop();
                char first = stk.top();
                
                if ((first == 'A' && second == 'B') || (first == 'C' && second == 'D')) {
                    
                    stk.pop();
                } else {
                    stk.push(second);
                }
            }
        }
        return stk.size();
    }
};
